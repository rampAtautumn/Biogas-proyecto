// helper.hpp
#ifndef helper_HPP
#define helper_HPP

#include <algorithm>
#include "constants.hpp"
#include "Op.hpp"
#include <string>
#include <string_view>
#include <vector>

namespace helper

{
    biogasconstants::variables value_change(biogasconstants::variables gen);
    extern bool combos[4][4][3];
    void helpercomb(int op1, int op2);
    void menu(biogasconstants::variables &gen, biogasconstants::variables &temp,biogasconstants::bascalcs &Bas, biogasconstants::purcalc &pur, biogasconstants::rescalc &res,biogasconstants::Ecalc &E, biogasconstants::nutcalc &nut);
    void pause();
    void creatobj();

    struct flagsinput
    {
        bool f_CH4 = false;
        bool Vsv = false;
        bool Vv = false;
    };

    struct flagsvalid
    {
        bool f_CH4v = false;
        bool Vsval = false;
        bool Volval = false;
    };

    extern flagsinput current;
    extern flagsvalid validations;

    class substracttypes
    {
    private:
        std::string nombre;
        std::vector<std::string> tipos = {"Residuos_animales",
                                      "Residuos_vegetales",
                                      "Residuos_industriales",
                                      "Residuos_domesticos",
                                      "Cultivos_energeticos",
                                      "Mixtos"};
        int indice;

    public:
        substracttypes(std::string n) : nombre(n) {}
        void showtypes();
        void askType();
        int getNumtypes();
    };

}
#endif
