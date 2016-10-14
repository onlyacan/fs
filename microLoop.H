micoCalcLoopCounter = 0; // it's a global variable

do {
    // only for testing
    //int i = 0;
    //string sp = " ";

    /*

    output << gg[i] << sp << Cs[i]  << sp << gs[i] << sp << Cl[i] << sp
           << Se[i] << sp << wne[i] << sp << T[i] <<  sp << Omega[i] << sp
           << Ce[i] << sp << Cl[i] 
           << "\n";
    */

    // store previous iteration for relaxation

    gg.storePrevIter();
    Cs.storePrevIter();
    gs.storePrevIter();
    Cl.storePrevIter();

    #include "kinetic/updateGrowthVelocity_LGK.H"
    
    #include "eqn/geEqn.H"
    #include "eqn/ggEqn.H"    
    #include "eqn/CsEqn.H"
    #include "eqn/gsEqn.H"
    #include "eqn/ClEqn.H"
    

    micoCalcLoopCounter += 1;        

 } while (micoCalcLoopCounter < 2);

