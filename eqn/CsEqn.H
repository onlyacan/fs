// Cs Equation
    // update the Cs: status: ok

    ad_sd = Ss * Ds / lsd; 
    
    fvScalarMatrix CsEqn(
        fvm:: ddt(gs, Cs)
        ==
        Csd * ddt_gs 
        + ad_sd * Csd - fvm:: Sp(ad_sd, Cs) // R2 
    ); 
    
    // CsEqn.relax();
    CsEqn.solve();
    Cs.relax();
    Info << "Cs updated" << endl;
