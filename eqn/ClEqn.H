

    glgf_phi = linearInterpolate(gl / gf * U) & mesh.Sf();
    

    // WB1994
    // constrain the Cl by introduce a coefficnet alpha_Cl in field/ClEqn.H
    // which equals to (ddt_gl + ad_ld)
    
    // the term from RB2015 added 
 
    alpha_Cl = Foam:: max(zeroValue_alpha_Cl, ddt_gl + ad_ld);

    
    fvScalarMatrix ClEqn(
        gl * fvm:: ddt(Cl)
        //+ fvm:: div(glgf_phi, Cl) 
        ==
        alpha_Cl * Ce - fvm:: Sp(alpha_Cl, Cl) 
        //+ Dl * fvm:: laplacian(gl, Cl)
        //+ Cd * fvc:: div(phi, gl/gf)
    );

    // ClEqn.relax();
    ClEqn.solve();
    Cl.relax();
    Info << "Cl updated" << endl;
