// learn from Miehe's doctor thesis


using namespace Foam;

TLoopCounter = 0;
do{
    TLoopCounter ++;
    T.storePrevIter();

    #include "CourantNo.H"
    // Momentum predictor
    //#include "UEqn.H"

    // --- PISO loop
    //#include "pisoLoop.H"
    
    

    #include "eqn/TEqn.H"

    
    #include "microLoop.H"

    // check the consistance
    diff_T  = Foam:: gMax(mag(( T.internalField() -  T.prevIter().internalField())/( T.prevIter().internalField() + S)));
    diff_gg = Foam:: gMax(mag((gg.internalField() - gg.prevIter().internalField())/(gg.prevIter().internalField() + S)));
    diff_Cs = Foam:: gMax(mag((Cs.internalField() - Cs.prevIter().internalField())/(Cs.prevIter().internalField() + S)));
    diff_gs = Foam:: gMax(mag((gs.internalField() - gs.prevIter().internalField())/(gs.prevIter().internalField() + S)));
    diff_Cl = Foam:: gMax(mag((Cl.internalField() - Cl.prevIter().internalField())/(Cl.prevIter().internalField() + S)));

    Info << " diff_T: " << diff_T 
         << " diff_gg: " << diff_gg 
         << " diff_Cs: " << diff_Cs 
         << " diff_gs: " << diff_gs 
         << " diff_Cl: " << diff_Cl 
         << endl; 

    converged = (diff_T <= tol_T) 
        &&(diff_gg <= tol_gg) 
        &&(diff_Cs <= tol_Cs) 
        &&(diff_gs <= tol_gs) 
        &&(diff_Cl <= tol_Cl);

    
        
        
    //converged = true;


} while (TLoopCounter <= MAX_TITER && !converged);



if(TLoopCounter >= MAX_TITER) {
    Info << "T loop: Maxinum number of iteration excecute, but solution is still not converged" << endl;
    return -1;
 }
 else{
    Info << "T converged in " << TLoopCounter << " iteration" << endl;
    old_ddt_gs = fvc:: ddt(gs); // used in next time step 
 }


