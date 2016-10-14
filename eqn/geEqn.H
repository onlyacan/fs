    // update the eutectic phase
    fvScalarMatrix geEqn
    (
        fvm:: ddt(ge) == ddt_ge
    );

    geEqn.relax();
    geEqn.solve();
    Info << "ge updated" << endl;
