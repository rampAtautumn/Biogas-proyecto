// vni.hpp
#ifndef vnio_HPP
#define vnio_HPP

#include "constants.hpp"

namespace valid
{

    // Validation
    bool validation(bc::variables &valid, bool f_CH4v = true, bool VSv = true, bool Vv = true); // f_CH4, VS y V_biogas
    bool option_changev(int op1, int op2);
    bool read_int(int& x);

    // input requests
    bc::variables input_request(bc::variables &in, bool f_CH4v = false, bool VSv = false, bool Vv = false);
    void update_vals(bc::variables &in, const bc::variables &temp, bool f_CH4v, bool VSv, bool Vv);

    //output
    void valout();
    void bascalcout(const bc::bascalcs &basres);
    void purityout(const bc::purcalc &puresults);
    void residuesout(const bc::rescalc &res);
    void Eout(const bc::Ecalc &Eres);
    void nutrientout(const bc::nutcalc &nutres);
};

#endif