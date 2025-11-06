#include <iostream>
#include "constants.hpp"
#include "vnio.hpp"
#include <string>

using bc::variables;

namespace valid
{
    variables input_request(variables &in, bool f_CH4v, bool VSv, bool Vv)
    {

        variables temp{};

        if (f_CH4v)
        {
            std::cout << "Enter methane fraction: ";
            std::cin >> temp.f_CH4;
        }
        if (VSv)
        {
            std::cout << "Enter volatile solids: ";
            std::cin >> temp.VS;
        }
        if (Vv)
        {
            std::cout << "Enter biogas volume: ";
            std::cin >> temp.V_biogas;
        }

        return temp;
    }
    void update_vals(bc::variables &in, const variables &temp, bool f_CH4v, bool VSv, bool Vv)
    {
        if (f_CH4v)
        {
            in.f_CH4 = temp.f_CH4;
        }
        if (VSv)
        {
            in.VS = temp.VS;
        }
        if (Vv)
        {
            in.V_biogas = temp.V_biogas;
        }
    }

    void valout()
    {
        std::cout << "Datos invalidos, vuelva a ingresar los datos." << std::endl
                  << "Recuerde que: "
                  << "f_CH4 debe ser un valor mayor a 0 y menor o igual a 0.8" << std::endl
                  << "VS debe ser mayor a 0 y menor o igual a 1, y el volumen debe ser mayor a 0" << std::endl;
    }
    void bascalcout(const bc::bascalcs &basres)
    {
        std::cout << "CH4 production: " << basres.CH4production << "m³" << std::endl
                  << "volatid solids on exit: " << basres.VSout << "Kg" << std::endl
                  << "Degraded volatid solids: " << basres.DegradVS << "kg" << std::endl
                  << "Real DE: " << basres.real_DE << std::endl
                  << "remain solids: " << basres.remain_solid << std::endl;
    }
    void purityout(const bc::purcalc &puresults)
    {
        std::cout << "CH4 percent: " << puresults.CH4_percent << std::endl
                  << "CO2 to CH4 relations: " << puresults.CO2_CH4_relation << std::endl
                  << "other gases: " << puresults.other_gas << std::endl;
    }
    void residuesout(const bc::rescalc &res)
    {
        std::cout << "total mass: " << res.total_mass << "kg" << std::endl
                  << "total solid mass: " << res.total_mass << "kg" << std::endl
                  << "total liquid mass: " << res.solid_mass << "kg" << std::endl
                  << "Solid volume: " << res.solid_v << "m³" << std::endl
                  << "liquid volume: " << res.liq_v << "m³" << std::endl;
    }
    void Eout(const bc::Ecalc &Eres)
    {
        std::cout << "Q: " << Eres.Q << "J" << std::endl
                  << "Theorical E: " << Eres.TE << "J" << std::endl
                  << "Theorical EE: " << Eres.TheoricalElectricE << "J" << std::endl
                  << "PCI: " << Eres.PCI << "J/m³" << std::endl
                  << "Bio E: " << Eres.BioEnergy << "J" << std::endl
                  << "Electric energy: " << Eres.ElectricEnergy << "J" << std::endl
                  << "Termical E performance : " << Eres.Termper << "J" << std::endl
                  << "Bio performance: " << Eres.bioperformance << std::endl;
    }
    void nutrientout(const bc::nutcalc &nutres)
    {
        std::cout << "Total N: " << nutres.Total_N << "kg" << std::endl
                  << "Total P: " << nutres.Total_P << "kg" << std::endl
                  << "Total K: " << nutres.Total_K << "kg" << std::endl
                  << "N charge: " << nutres.N_charge << "kg" << std::endl
                  << "P charge: " << nutres.P_charge << "kg" << std::endl
                  << "K charge: " << nutres.K_charge << "kg" << std::endl;
    }
}
