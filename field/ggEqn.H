
volScalarField gg
(
   IOobject
   (
    "gg",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gg0
 );


// fields updated based only on gg
volScalarField gl
(
   IOobject
   (
    "gl",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, gl0
 );

dimensionedScalar ddt_gl0("ddt_gl0", dimensionlessRate, 0.0);
volScalarField ddt_gl
(
   IOobject
   (
    "ddt_gl",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, ddt_gl0
 );


// used only in gg equation
dimensionedScalar Omega0("Omega0", dimensionless, 0.0);
volScalarField Omega
(
   IOobject
   (
    "Omega",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Omega0
 );


dimensionedScalar ivIvr0("ivIvr0", dimensionless, 0.0);
volScalarField ivIvr
(
   IOobject
   (
    "ivIvr",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, ivIvr0
 );


dimensionedScalar wne0("wne0", velocity, 0.0);
volScalarField wne
(
   IOobject
   (
    "wne",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, wne0
 );


// updated in kinetic/updateGLK.H
dimensionedScalar smarker0("smarker0", dimensionless, 0.0);
volScalarField smarker
(
   IOobject
   (
    "smarker",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, smarker0
 );




