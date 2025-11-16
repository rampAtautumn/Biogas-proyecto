#include "constants.hpp"
#include "helpers.hpp"
#include "Op.hpp"
#include <iostream>

namespace operations
{
    void Bascalc(biogasconstants::variables &in, biogasconstants::bascalcs &Basout)
    {
        Basout.CH4production = in.V_biogas * in.f_CH4;
        Basout.VSout = in.VS * biogasconstants::Avg_DE;
        Basout.DegradVS = in.VS - Basout.VSout;
        Basout.real_DE = ((in.VS - Basout.VSout) / in.VS) * 100;
        Basout.remain_solid = Basout.VSout / in.VS;
    }

    void purity(biogasconstants::variables &in, biogasconstants::purcalc &purout)
    {
        purout.CH4_percent = in.f_CH4 * 100;
        purout.other_gas = (biogasconstants::f_CO2 + biogasconstants::f_H2O + biogasconstants::f_H2S + biogasconstants::f_trazas) * 100;
        purout.CO2_CH4_relation = biogasconstants::f_CO2 / purout.CH4_percent;
    }

    void residues(biogasconstants::variables &in, biogasconstants::rescalc &resout)
    {
        resout.total_mass = in.VS / biogasconstants::Factor_residuo_solido;
        resout.solid_mass = resout.total_mass * biogasconstants::Factor_residuo_solido;
        resout.liquid_mass = resout.total_mass * biogasconstants::Factor_residuo_liquído;
        resout.solid_v = resout.solid_mass / biogasconstants::Densidad_media;
        resout.liq_v = resout.liquid_mass / biogasconstants::Densidad_media;
    }

    void Energy(biogasconstants::variables &in, biogasconstants::Ecalc &Eout)
    {
        Eout.TE = in.V_biogas * in.f_CH4 * biogasconstants::PCI_CH4;
        Eout.TheoricalElectricE = Eout.TE * biogasconstants::Eta_Electrica;
        Eout.Q = Eout.TE * biogasconstants::Eta_Termica;

        Eout.bioperformance = (Eout.Q / Eout.TE) * 100;
        Eout.Termper = Eout.bioperformance;

        Eout.PCI = biogasconstants::PCI_CH4;
        Eout.BioEnergy = Eout.Q;
        Eout.ElectricEnergy = Eout.TheoricalElectricE;
    }

    void nutrients(biogasconstants::variables &in, biogasconstants::nutcalc &nutout, biogasconstants::rescalc &r)
    {
        nutout.Total_N = (in.VS * 0.007) * (1 - biogasconstants::Perdida_N);
        nutout.Total_P = (in.VS * 0.004) * (1 - biogasconstants::Perdida_P);
        nutout.Total_K = (in.VS * 0.006) * (1 - biogasconstants::Perdida_K);
        nutout.N_charge = nutout.Total_N / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
        nutout.P_charge = nutout.Total_P / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
        nutout.K_charge = nutout.Total_K / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
    }

}