#include <PeleLM.H>
#include <pelelm_prob.H>
#include <AMReX_ParmParse.H>

void PeleLM::readProbParm()
{
        amrex::ParmParse pp("prob");

        pp.query("P_mean", PeleLM::prob_parm->P_mean);
        pp.query("Zst",    PeleLM::prob_parm->Zst);
        pp.query("T_in",   PeleLM::prob_parm->T_in);
        pp.query("V_in",   PeleLM::prob_parm->V_in);

        PeleLM::prob_parm->splitx = 0.01;
        PeleLM::prob_parm->midtanh = 0.008;
        PeleLM::prob_parm->widthtanh = 0.001; 

        // TODO: somewhat hard coded bath, fuel and oxid IDs 
        // should exist somewhere in PeleLM.
        PeleLM::prob_parm->bathID = N2_ID;  
        PeleLM::prob_parm->fuelID = CH4_ID;  
        PeleLM::prob_parm->oxidID = O2_ID;  
}