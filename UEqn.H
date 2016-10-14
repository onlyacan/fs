rhof_tilde = 1.0 - betaT * (T - Tref) - betaC * (Cl - Cref); // chekced
K = (lambda2 * lambda2 * Foam::pow(gf, 3)) / (180 * Foam:: pow(1.0 - gf, 2)); // checked


fvVectorMatrix UEqn
(
    fvm:: ddt(U)
    + 1.0 / gf * fvm:: div(phi, U)
    ==
    nu * fvm:: laplacian (U)
    + rhof_tilde  * gf * g  // original: + rhof_tilde / rho0 * gf * g 
    - fvm:: Sp(nu / K * gf, U)
);

if (piso.momentumPredictor())
{
    /** orignal 
    solve(UEqn == -1/rho0 * gf * fvc:: grad(p));  // kenematic pressure, don't have to change the PISO p loop
    **/
    solve(UEqn == -1 * gf * fvc:: grad(p));  // kenematic pressure, don't have to change the PISO p loop
}


/**** old impl.
 * 
 * 
        fvVectorMatrix UEqn
        (
            fvm::ddt(U)
          + 1.0/gf * fvm::div(phi, U)
          - fvm::laplacian(nu, U)
        );
        
 

        if (piso.momentumPredictor())
        {
            solve(UEqn == - gf * fvc::grad(p));  // kenematic pressure, don't have to change the PISO p loop
        }
*/
