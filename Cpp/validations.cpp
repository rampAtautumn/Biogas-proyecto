#include "constants.hpp"
#include <iostream>
#include <limits>
#include "helpers.hpp"
#include "vnio.hpp"

using bc::varc;
using bc::variables;

namespace valid
{

    bool validation(bc::variables &valid, bool f_CH4v, bool VSv, bool Vv, int depth)
    {
        const int MAX_DEPTH = 5; // Limite de reintentos

        bool all_valid = true;

        if (f_CH4v)
        {
            bool cond = (valid.f_CH4 > 0 && valid.f_CH4 <= 0.8);
            h::validations.f_CH4v = cond;
            all_valid = all_valid && cond;
        }

        if (VSv)
        {
            bool cond = (valid.VS > 0 && valid.VS <= 1);
            h::validations.Vsval = cond;
            all_valid = all_valid && cond;
        }

        if (Vv)
        {
            bool cond = (valid.V_biogas > 0);
            h::validations.Volval = cond;
            all_valid = all_valid && cond;
        }

        if (all_valid)
            return true;

        // Límite de recursión alcanzado
        if (depth >= MAX_DEPTH)
        {
            std::cout << "Demasiados intentos fallidos. Abortando validación.\n";
            return false;
        }

        valout();

        // Pedir nuevos datos solo para los que no son válidos
        bc::variables temp = input_request(valid,
                                           !h::validations.f_CH4v,
                                           !h::validations.Vsval,
                                           !h::validations.Volval);

        update_vals(valid, temp,
                    !h::validations.f_CH4v,
                    !h::validations.Vsval,
                    !h::validations.Volval);

        // Llamada recursiva con contador incrementado
        return validation(valid, true, true, true, depth + 1);
    }

    bool option_changev(int op1, int op2)
    {
        for (int i = 0; i < bc::arrsearchvarc; i++)
        {
            if (op2 != 0)
            {
                for (int j = 0; j < bc::arrsearchvarc; j++)
                {
                    if ((op1 == varc[i] && op2 == varc[j]) || (op1 == varc[j] && op2 == varc[i]))
                    {
                        return true;
                    }
                }
            }
            else if (op1 == varc[i])
            {
                return true;
            }
        }
        return false;
    }
    bool read_int(int &x)
    {
        if (std::cin >> x)
            return true;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
