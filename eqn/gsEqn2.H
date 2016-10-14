    // update gs from Eqn[4]
    gl_mul_Cl_Cd = gl * (Cl - Cd);
    amul_phi = linearInterpolate((gd/gf * Cd + gl/gf * Cl) * U) & mesh.Sf();

    fvScalarMatrix gsEqn
    (
        (1-kp) * Cd * fvm:: ddt(gs)
        == 
        ddt_Cd - fvm:: Sp(ddt_Cd, gs)
        + fvc:: ddt(gl_mul_Cl_Cd)
        + fvc:: div(amul_phi)
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
