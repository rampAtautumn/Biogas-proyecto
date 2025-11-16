#include <algorithm>
#include "constants.hpp"
#include <iostream>
#include <string>
#include <string_view>
#include "helpers.hpp"
#include "Op.hpp"
#include "vnio.hpp"
#include <vector>
#include <windows.h>


int main(void)
{
    biogasconstants::variables gen;
    biogasconstants::variables temp;
    biogasconstants::bascalcs Bas;
    biogasconstants::purcalc pur;
    biogasconstants::rescalc res;
    biogasconstants::Ecalc E;
    biogasconstants::nutcalc nut;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    gen.f_CH4 = 0;
    gen.VS = 0;
    gen.V_biogas = 0;

    helper::menu(gen, temp, Bas, pur, res, E, nut);
    return 0;
}