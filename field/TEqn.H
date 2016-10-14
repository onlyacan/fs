Info<< "Reading field T\n" << endl;

volScalarField T
(
 IOobject
 (
  "T",
  runTime.timeName(),
  mesh,
  IOobject::MUST_READ,
  IOobject::AUTO_WRITE
  ),
 mesh
 );
    
// used only in T equation
/*
volScalarField ddt_T
(
   IOobject
   (
    "ddt_T",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, ddt_T0 
 );
*/


/* following variable are determined after T is updated */

//Concentration at dendrite envelop
dimensionedScalar Ce0("Ce0", C0);
volScalarField Ce
(
   IOobject
   (
    "Ce",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Ce0
 );

// concentration in inter-dendritic phase d
// it's assumed (simplified) to be same as the Ce
dimensionedScalar Cd0("Cd0", C0);
volScalarField Cd
(
   IOobject
   (
    "Cd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Cd0
 );

//Concentration at the inter-dendritic and extra-dendritic 
//
dimensionedScalar Cl_star0("Cl_star0", C0);
volScalarField Cl_star
(
   IOobject
   (
    "Cl_star",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Cl_star0
 );


dimensionedScalar Csd0("Csd0", Ce0 * kp);
volScalarField Csd
(
   IOobject
   (
    "Csd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Csd0
 );


