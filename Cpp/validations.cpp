#include "constants.hpp"
#include <iostream>
#include <limits>
#include "helpers.hpp"
#include "vnio.hpp"

using bc::varc;
using bc::variables;

namespace valid
{


    bool validation(bc::variables &valid, bool f_CH4v, bool VSv, bool Vv)
    {
        bool valid_aux = false;

        if (f_CH4v)
        {
            bool cond = (valid.f_CH4 > 0 && valid.f_CH4 <= 0.8);
            if (cond)
                h::validations.f_CH4v = true;
            valid_aux = valid_aux || cond;
        }

        if (VSv)
        {
            bool cond = (valid.VS > 0 && valid.VS <= 1);
            if (cond)
                h::validations.Vsval = true;
            valid_aux = valid_aux || cond;
        }

        if (Vv)
        {
            bool cond = (valid.V_biogas > 0);
            if (cond)
                h::validations.Volval = true;
            valid_aux = valid_aux || cond;
        }

        if (valid_aux)
            return true;

        valout();
        input_request(valid, h::validations.f_CH4v, h::validations.Vsval, h::validations.Volval);
        return validation(valid, h::validations.f_CH4v, h::validations.Vsval, h::validations.Volval);
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
