// Constants.hpp

#ifndef Constants_HPP
#define Constants_HPP

namespace biogasconstants
{
    // Calculadora basica
    constexpr double Avg_DE = 0.6;

    // Composición promedio
    constexpr double f_CO2 = 0.35;
    constexpr double f_H2S = 0.01;
    constexpr double f_H2O = 0.02;
    constexpr double f_trazas = 0.02;

    // Residuos
    constexpr double Factor_residuo_solido = 0.3;
    constexpr double Factor_residuo_liquído = 0.7;
    constexpr double Densidad_media = 1000; //(Kg/m3)

    // Nutrientes
    constexpr double Perdida_N = 0.1;
    constexpr double Perdida_P = 0.05;
    constexpr double Perdida_K = 0.05;

    // calc energetica
    constexpr double PCI_CH4 = 35.8e6; //(Mj/m3)
    constexpr double Eta_Electrica = 0.35;
    constexpr double Eta_Termica = 0.85;

    constexpr int varc[] = {1, 2, 3};
    constexpr int arrsearchvarc = sizeof(varc) / sizeof(varc[0]);

    struct variables
    {
        double f_CH4;
        double VS;
        double V_biogas;
    };

    struct bascalcs
    {
        // basic calc
        double CH4production = 0;
        double VSout = 0;
        double DegradVS = 0;
        double real_DE = 0;
        double remain_solid = 0;
    };

    struct purcalc
    {
        // purity
        double CH4_percent = 0;
        double other_gas = 0;
        double CO2_CH4_relation = 0;
    };

    struct rescalc
    {
        // residues
        double total_mass = 0;
        double solid_mass = 0;
        double liquid_mass = 0;
        double solid_v = 0;
        double liq_v = 0;
        bool masa_calculada = false;
    };

    struct Ecalc
    {
        // Energy
        double Q = 0;
        double TE = 0;
        double PCI = 0;
        double BioEnergy = 0;
        double Termper = 0;
        double ElectricEnergy = 0;
        double TheoricalElectricE = 0;
        double bioperformance = 0;
    };

    struct nutcalc
    {
        // nutrients
        double Total_N = 0;
        double Total_P = 0;
        double Total_K = 0;
        double N_charge = 0;
        double P_charge = 0;
        double K_charge = 0;
    };

}
#endif