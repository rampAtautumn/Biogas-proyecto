//Constants.hpp

#ifndef Constants_HPP
#define Constants_HPP

namespace bc{
    //Calculadora basica
    constexpr double Avg_DE = 0.6;

    //Composición promedio
    constexpr double f_CO2 = 0.35;
    constexpr double f_H2S = 0.01;
    constexpr double f_H2O = 0.02;
    constexpr double f_trazas = 0.02;

    //Residuos
    constexpr double Factor_residuo_solido = 0.3;
    constexpr double Factor_residuo_liquído = 0.7;
    constexpr double Densidad_media = 1000; //(Kg/m3)

    //Nutrientes
    constexpr double Perdida_N = 0.1;
    constexpr double Perdida_P = 0.05;
    constexpr double Perdida_K = 0.05;

    //calc energetica
    constexpr double PCI_CH4 = 35.8; //(Mj/m3)
    constexpr double Eta_Electrica = 0.35; 
    constexpr double Eta_Termica = 0.85;
  
    constexpr int varc[] ={1, 2, 3};
    constexpr int arrsearchvarc = sizeof(varc)/sizeof(varc[0]);

    struct variables
    {
        double f_CH4;
        double VS;
        double V_biogas;
    };

    struct bascalcs
    {
     //basic calc
        double CH4production;
        double VSout;
        double DegradVS;
        double real_DE;
        double remain_solid;
    };

    struct purcalc{
     //purity
     double CH4_percent;
     double other_gas;
     double CO2_CH4_relation;
    };

    struct rescalc{
     //residues
     double total_mass;
     double solid_mass;
     double liquid_mass;
     double solid_v;
     double liq_v;
     bool masa_calculada = false;
    };

    struct Ecalc{
     //Energy
     double Q;
     double TE;
     double PCI;
     double BioEnergy;
     double Termper;
     double ElectricEnergy;
     double TheoricalElectricE;
     double bioperformance;
    };

    struct nutcalc{
     //nutrients
     double Total_N;
     double Total_P;
     double Total_K;
     double N_charge;
     double P_charge;
     double K_charge;
    };
    
}

#endif