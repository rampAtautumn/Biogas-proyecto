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
    bc::variables gen;
    bc::variables temp;
    bc::bascalcs Bas;
    bc::purcalc pur;
    bc::rescalc res;
    bc::Ecalc E;
    bc::nutcalc nut;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    gen.f_CH4 = 0;
    gen.VS = 0;
    gen.V_biogas = 0;

    h::menu(gen, temp, Bas, pur, res, E, nut);
    return 0;
}