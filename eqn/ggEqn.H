// update wne 


Se = (3.0 * Foam:: pow((1.0 - gl),(2.0/3.0)))/ Rf * gl;
fvScalarMatrix ggEqn
(
    fvm::ddt(gg) == Se * wne  
);  
    
//ggEqn.relax();
ggEqn.solve();
gg.relax();

gg = Foam:: min(1.0, gg); // !! not consider the ge, otherwiese it may change the Cl
Info << "gg updated" << endl;

// some relative field dependent on gg
gl = 1.0 - gg;  
ddt_gl = fvc:: ddt(gl);
Re = Foam:: pow((1.0 - gl),(1.0/3.0)) * Rf * 0.999999;     

//diffusion length at interface l/d and s/d
// should not let it stay initila value 0, otherwise dived by 0 error occurs
lld = Re * (1.0 - 3.0/2.0 * Re * (Rf * Rf - Re * Re)/(Rf * Rf * Rf - Re * Re * Re)); 
// problem arised when we try to use vector calculation:
//!!!!!! Prolbem is when gl = 0.0, Re = Rf, cause floating point error
// one solution is add a small value to the denominator
// another solution is say Re can never reach Rf even when gl = 0.0, but 0.999 * Rf
// dimensionedScalar x("x", lengthDims, 1e-8);
// lld = x;
lsd = lld * 1000; 



