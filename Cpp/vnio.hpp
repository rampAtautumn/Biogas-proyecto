// vni.hpp
#ifndef vnio_HPP
#define vnio_HPP

#include "constants.hpp"

namespace validations
{

    // Validation
   // vnio.hpp
    bool validation(biogasconstants::variables &valid, bool f_CH4v = true, bool VSv = true, bool Vv = true, int depth = 0);
    bool option_changev(int op1, int op2);
    bool read_int(int& x);

    // input requests
    biogasconstants::variables input_request(biogasconstants::variables &in, bool f_CH4v = false, bool VSv = false, bool Vv = false);
    void update_vals(biogasconstants::variables &in, const biogasconstants::variables &temp, bool f_CH4v, bool VSv, bool Vv);

    //output
    void valout();
    void bascalcout(const biogasconstants::bascalcs &basres);
    void purityout(const biogasconstants::purcalc &puresults);
    void residuesout(const biogasconstants::rescalc &res);
    void Eout(const biogasconstants::Ecalc &Eres);
    void nutrientout(const biogasconstants::nutcalc &nutres);
};

#endif