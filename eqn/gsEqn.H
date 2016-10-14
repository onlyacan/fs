    // update gs from Eqn[4]
    //gl_mul_Cl_Cd = gl * (Cl - Cd);
    //CdTerm = ddt_Cd + 1.0 / gf * fvc:: div(phi, Cd);
    //CdTerm = ddt_Cd + 1.0 / gf * (U & fvc:: grad(Cd));
    //amul_phi = linearInterpolate(gl/gf * (Cl - Cd)  * U) & mesh.Sf();
    
    ad_ld = Se * Dl / lld; 
    
    fvScalarMatrix gsEqn
    (
        (Cd - Csd) * fvm:: ddt(gs)
        == 
        gd * ddt_Cd
        + ad_sd * (Csd - Cs) 
        + ad_ld * (Cd - Cl)
        
     );
 
    //gsEqn.relax();
    gsEqn.solve();
    gs.relax();
    
    // some values dependent on gs
    ddt_gs = fvc:: ddt(gs);

    gd = gg - gs;
    gf = gd + gl;
    gse = gs + ge;
    
    Info << "gs updated" << endl;
