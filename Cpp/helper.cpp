#include <algorithm>
#include "constants.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include "helpers.hpp"
#include "vnio.hpp"
#include <vector>

using bc::variables;

namespace h
{
    flagsinput current;
    flagsvalid validations;

    variables value_change(variables gen)
    {
        int choice = 0;

        do
        {
            while (true)
            {
                std::cout << "------Cambio de variables----" << std::endl
                          << "seleccione lo que desea cambiar" << std::endl;
                std::cout << "1.- Todas Las variabes" << std::endl
                          << "2.- dos variables" << std::endl
                          << "3.- Una variable" << std::endl
                          << "4.-Salir" << std::endl;
                std::cout << "\nIngrese una opción: ";
                std::cin >> choice;

                if (!valid::read_int(choice))
                {
                    std::cout << "Error, solo se admiten números.\n";
                    continue;
                }
                if (choice < 0 || choice > 4)
                {
                    std::cout << "Error, el numero esta Fuera de rango.\n";
                    continue;
                }
                break;
            }

            switch (choice)
            {
            case 1:
            {
                valid::input_request(gen, true, true, true);
                break;
            }

            case 2:
            {
                int op1 = 0;
                int op2 = 0;
                std::cout << "¿cuales 2 variables desea cambiar?" << std::endl;
                std::cin >> op1 >> op2;
                valid::option_changev(op1, op2);
                helpercomb(op1, op2);
                valid::input_request(gen, current.f_CH4, current.Vsv, current.Vv);
                break;
            }

            case 3:
            {
                int op1 = 0;
                int op2 = 0;
                std::cout << "¿cual variable desea cambiar?" << std::endl;
                std::cin >> op1;
                valid::option_changev(op1, op2);
                helpercomb(op1, op2);
                valid::input_request(gen, current.f_CH4, current.Vsv, current.Vv);
                break;
            }
            case 4:
            {
                std::cout << "Saliendo..." << std::endl;
                break;
            }
            default:
                std::cout << "opción invalida" << std::endl;
            }
        } while (choice != 4);

        return gen;
    }
    void helpercomb(int op1, int op2)
    {
        bool combos[4][4][3] = {0};

        combos[1][0][0] = true;
        combos[2][0][1] = true;
        combos[3][0][2] = true;

        combos[1][2][0] = true;
        combos[1][2][1] = true;
        combos[1][3][0] = true;
        combos[1][3][2] = true;
        combos[2][3][1] = true;
        combos[2][3][2] = true;

        current.f_CH4 = combos[op1][op2][0];
        current.Vsv = combos[op1][op2][1];
        current.Vv = combos[op1][op2][2];

        return;
    }

    void substracttypes::askType()
    {
        bool typeval;
        std::string buscar;
        std::cout << "Ingresa el tipo de sustrato, pueden ser: "
                  << " 1.-Residuos_animales, "
                  << " 2.-Residuos_vegetales, "
                  << " 3.-Residuos_industriales, "
                  << " 4.-Residuos_domesticos, "
                  << " 5.-Cultivos_energeticos, "
                  << " 6.-Mixtos."
                  << std::endl;
        std::cin >> buscar;

        for (const auto &t : tipos)
        {
            if (t == buscar)
            {
                std::cout << buscar << " SI pertenece al grupo.\n";
            }
        }
        std::cout << buscar << " NO existe en los tipos registrados.\n";
    }

    void substracttypes::showtypes()
    {
        if (tipos.empty())
        {
            std::cout << "No hay tipos de sustrato registrados.\n";
            return;
        }

        std::cout << "Tipos de sustrato:\n";
        for (const auto &t : tipos)
        {
            std::cout << "- " << t << "\n";
        }
    }

    int substracttypes::getNumtypes()
    {
        return tipos.size();
    }

    void pause()
    {
        std::cout << "\nPresione cualquier tecla para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    void menu(bc::variables &gen, bc::variables &temp, bc::bascalcs &Bas, bc::purcalc &pur, bc::rescalc &res, bc::Ecalc &E, bc::nutcalc &nut)
    {
        int choice = -1;
        while (choice != 0)
        {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif

            std::cout << "-----Bienvenido al programa----" << std::endl
                      << "porfavor seleccione una opción" << std::endl
                      << "1.-Calculadora basica de los procedimientos del biogas" << std::endl
                      << "2.-Porcentaje de pureza basada en metano y gases producidos" << std::endl
                      << "3.-Residuos" << std::endl
                      << "4.-Calculadora energetica" << std::endl
                      << "5.-Calculadora de nutrientes" << std::endl
                      << "6.-Cambiar valores" << std::endl
                      << "7.- Insertar un tipo de sustrato" << std::endl
                      << "0.- salir" << std::endl;
            std::cin >> choice;

            while (true)
            {
                if (!valid::read_int(choice))
                {
                    std::cout << "Error, solo se admiten números.\n";
                    continue;
                }
                if (choice < 0 || choice > 7)
                {
                    std::cout << "Error, el numero esta Fuera de rango.\n";
                    continue;
                }
                break;
            }
            switch (choice)
            {
            case 1:
                if (h::validations.f_CH4v && h::validations.Vsval && h::validations.Volval)
                {
                    op::Bascalc(gen, Bas);
                    valid::bascalcout(Bas);
                    pause();
                    break;
                }
                else
                {
                    temp = valid::input_request(gen, true, true, true);
                    if (!valid::validation(temp, true, true, true))
                    {
                        std::cout << "Error: valores inválidos, no se puede calcular.\n";
                        break;
                    }
                    valid::update_vals(gen, temp, true, true, true);
                    h::validations.f_CH4v = true;
                    h::validations.Vsval = true;
                    h::validations.Volval = true;

                    op::Bascalc(gen, Bas);
                    valid::bascalcout(Bas);
                    pause();
                    break;
                }

            case 2:
                if (h::validations.f_CH4v && h::validations.Vsval && h::validations.Volval)
                {
                    op::purity(gen, pur);
                    valid::purityout(pur);
                    pause();
                    break;
                }
                else
                {
                    temp = valid::input_request(gen, true, false, false);
                    if (!valid::validation(temp, true, true, true))
                    {
                        std::cout << "Error: valores inválidos, no se puede calcular.\n";
                        break;
                    }
                    valid::update_vals(gen, temp, true, false, false);
                    h::validations.f_CH4v = true;
                    h::validations.Vsval = true;
                    h::validations.Volval = true;

                    op::purity(gen, pur);
                    valid::purityout(pur);
                    pause();
                    break;
                }
            case 3:
                if (h::validations.f_CH4v && h::validations.Vsval && h::validations.Volval)
                {
                    op::residues(gen, res);
                    valid::residuesout(res);
                    pause();
                    break;
                }
                else
                {
                    temp = valid::input_request(gen, false, true, false);
                    if (!valid::validation(temp, true, true, true))
                    {
                        std::cout << "Error: valores inválidos, no se puede calcular.\n";
                        break;
                    }
                    valid::update_vals(gen, temp, false, true, false);
                    h::validations.f_CH4v = true;
                    h::validations.Vsval = true;
                    h::validations.Volval = true;

                    op::residues(gen, res);
                    valid::residuesout(res);
                    pause();
                    break;
                }

            case 4:
                if (h::validations.f_CH4v && h::validations.Vsval && h::validations.Volval)
                {
                    op::Energy(gen, E);
                    valid::Eout(E);
                    pause();
                    break;
                }
                else
                {
                    temp = valid::input_request(gen, true, false, true);
                    if (!valid::validation(temp, true, true, true))
                    {
                        std::cout << "Error: valores inválidos, no se puede calcular.\n";
                        break;
                    }
                    valid::update_vals(gen, temp, true, false, true);
                    h::validations.f_CH4v = true;
                    h::validations.Vsval = true;
                    h::validations.Volval = true;

                    op::Energy(gen, E);
                    valid::Eout(E);
                    pause();
                    break;
                }
            case 5:
                if (h::validations.f_CH4v && h::validations.Vsval && h::validations.Volval)
                {
                    op::nutrients(gen, nut, res);
                    valid::nutrientout(nut);
                    pause();
                    break;
                }
                else
                {
                    temp = valid::input_request(gen, false, true, false);
                    if (!valid::validation(temp, true, true, true))
                    {
                        std::cout << "Error: valores inválidos, no se puede calcular.\n";
                        break;
                    }
                    valid::update_vals(gen, temp, false, true, false);
                    h::validations.f_CH4v = true;
                    h::validations.Vsval = true;
                    h::validations.Volval = true;

                    op::nutrients(gen, nut, res);
                    valid::nutrientout(nut);
                    pause();
                    break;
                }
            case 6:
                value_change(gen);
                pause();
                break;
            case 7:
                creatobj();
                pause();
                break;
            default:
                std::cout << "Error, opción invalida." << std::endl;
                ;
            }
        }
    }

    void creatobj()
    {
        substracttypes tipos("Sustratos");

        tipos.askType();
        tipos.showtypes();
        tipos.getNumtypes();
    }
}
