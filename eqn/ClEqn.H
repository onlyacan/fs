

    //glgf_phi = linearInterpolate(gl / gf * U) & mesh.Sf();
    

    // WB1994
    // constrain the Cl by introduce a coefficnet alpha_Cl in field/ClEqn.H
    // which equals to (ddt_gl + ad_ld)
 
    alpha_Cl = Foam:: max(zeroValue_alpha_Cl, ddt_gl + ad_ld);

    
    fvScalarMatrix ClEqn(
        gl * fvm:: ddt(Cl)
        ==
        alpha_Cl * Ce - fvm:: Sp(alpha_Cl, Cl) 
    );

    // ClEqn.relax();
    ClEqn.solve();
    Cl.relax();
    Info << "Cl updated" << endl;
