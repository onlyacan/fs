// eutectic phase
dimensionedScalar ge0("ge0", dimensionless, 0.0);
volScalarField ge
(
   IOobject
   (
    "ge",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, ge0
 );

dimensionedScalar ddt_ge0("ddt_ge0", dimensionlessRate, 0.0);
volScalarField ddt_ge
(
   IOobject
   (
    "ddt_ge",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, ddt_ge0
 );
