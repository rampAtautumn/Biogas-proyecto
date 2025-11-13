#include "constants.hpp"
#include "helpers.hpp"
#include "Op.hpp"
#include <iostream>

namespace op
{
    void Bascalc(bc::variables &in, bc::bascalcs &Basout)
    {
        Basout.CH4production = in.V_biogas * in.f_CH4;
        Basout.VSout = in.VS * bc::Avg_DE;
        Basout.DegradVS = in.VS - Basout.VSout;
        Basout.real_DE = ((in.VS - Basout.VSout) / in.VS) * 100;
        Basout.remain_solid = Basout.VSout / in.VS;
    }

    void purity(bc::variables &in, bc::purcalc &purout)
    {
        purout.CH4_percent = in.f_CH4 * 100;
        purout.other_gas = (bc::f_CO2 + bc::f_H2O + bc::f_H2S + bc::f_trazas) * 100;
        purout.CO2_CH4_relation = bc::f_CO2 / purout.CH4_percent;
    }

    void residues(bc::variables &in, bc::rescalc &resout)
    {
        resout.total_mass = in.VS / bc::Factor_residuo_solido;
        resout.solid_mass = resout.total_mass * bc::Factor_residuo_solido;
        resout.liquid_mass = resout.total_mass * bc::Factor_residuo_liquído;
        resout.solid_v = resout.solid_mass / bc::Densidad_media;
        resout.liq_v = resout.liquid_mass / bc::Densidad_media;
    }

    void Energy(bc::variables &in, bc::Ecalc &Eout)
    {
        Eout.TE = in.V_biogas * in.f_CH4 * bc::PCI_CH4;
        Eout.TheoricalElectricE = Eout.TE * bc::Eta_Electrica;
        Eout.Q = Eout.TE * bc::Eta_Termica;

        Eout.bioperformance = (Eout.Q / Eout.TE) * 100;
        Eout.Termper = Eout.bioperformance;

        Eout.PCI = bc::PCI_CH4;
        Eout.BioEnergy = Eout.Q;
        Eout.ElectricEnergy = Eout.TheoricalElectricE;
    }

    void nutrients(bc::variables &in, bc::nutcalc &nutout, bc::rescalc &r)
    {
        nutout.Total_N = (in.VS * 0.007) * (1 - bc::Perdida_N);
        nutout.Total_P = (in.VS * 0.004) * (1 - bc::Perdida_P);
        nutout.Total_K = (in.VS * 0.006) * (1 - bc::Perdida_K);
        nutout.N_charge = nutout.Total_N / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
        nutout.P_charge = nutout.Total_P / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
        nutout.K_charge = nutout.Total_K / (nutout.N_charge + nutout.Total_P + nutout.Total_K);
    }

}