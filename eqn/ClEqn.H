

    //glgf_phi = linearInterpolate(gl / gf * U) & mesh.Sf();
    

    // WB1994
    
    fvScalarMatrix ClEqn(
        fvm:: ddt(gl, Cl)
        ==
        Ce * ddt_gl
        + ad_ld * Ce - fvm:: Sp(ad_ld, Cl)
    );

    // ClEqn.relax();
    ClEqn.solve();
    Cl.relax();
    Info << "Cl updated" << endl;
