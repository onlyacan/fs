// gs0 in the initialFields.H
volScalarField gs
(
   IOobject
   (
    "gs",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gs0
 );

// fields used only by gs
volScalarField CdTerm
(
   IOobject
   (
    "CdTerm",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, dimensionedScalar("CdTerm0", dimensionlessRate, 0.0)
 );


// fields updated based only on gs

dimensionedScalar ddt_gs0("ddt_gs0", dimensionlessRate, 0.0);
volScalarField ddt_gs
(
   IOobject
   (
    "ddt_gs",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, 
   ddt_gs0
 );


// declared in initialFields.H
volScalarField gd
(
   IOobject
   (
    "gd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gd0
 );

// initial value defined in initialFields.H
volScalarField gf
(
   IOobject
   (
    "gf",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gf0
 );



// simply gse = gs + ge
dimensionedScalar gse0("gse0", dimensionless, 0.0);
volScalarField gse
(
   IOobject
   (
    "gse",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gse0
 );


// used only by gs equation

dimensionedScalar ddt_Cd0("ddt_Cd0", dimensionlessRate, 0.0);
volScalarField ddt_Cd
(
   IOobject
   (
    "ddt_Cd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, 
   ddt_Cd0
 );
