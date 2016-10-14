const int MAX_TITER = 100; // Miehe read it from a property dict "fsUpdate"
//double initResd = 0.0;
//double finalResd = 0.0;
//double residualTolerence = 1.0e-6;


Foam::solverPerformance solPerf;
bool converged = false;
double diff_T = 1.0, diff_gg=1.0, diff_Cs=1.0, diff_gs=1.0, diff_Cl=1.0; // use normilised difference 
double tol_T = 1e-5, tol_gg = 1e-5, tol_Cs = 1e-5, tol_gs = 1e-5, tol_Cl = 1e-5; // tolerence