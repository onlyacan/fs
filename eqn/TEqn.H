    
fvScalarMatrix TEqn
(
 cp * fvm:: ddt(T)
 //+ cp * fvm:: div(phi, T)
 ==
 1.0 / rho * fvm:: laplacian(k, T)
 + L * old_ddt_gs
 + Leut * ddt_ge // eutectic reaction
 + ddt_T0 * cp // specified heat sink for 0D test
 );  
    
TEqn.relax();
solPerf = TEqn.solve();
T.relax();



// version 3.0 changed, Miehe user lduMatrix:: sovlerPerformance
// more infomation see ./src/OpenFOAM/lnInclude/lduMatrix.H
/*
  initResd = solPerf.initialResidual();
  finalResd = solPerf.finalResidual();
  niter += solPerf.nIterations();
*/

// update some Temperature-dependent concentration
Cl_star = Foam:: min(Ceut, Foam:: max(C0, (T - Tf)/ ml)); // contrained by Ceut > Cl_star
Ce = Cl_star;
Cd = Cl_star;
Csd = kp * Ce;

ddt_Cd = fvc:: ddt(Cd);


Info << "one T updating iteration finished" << endl;
