/************* interface area per unit volume *******************/
// Se, Ss

dimensionedScalar Se0("Se0", areaPerVolumn, 0.0);
volScalarField Se
(
   IOobject
   (
    "Se",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Se0
 );

dimensionedScalar Ss0("Ss0", areaPerVolumn, 0.0);
volScalarField Ss
(
   IOobject
   (
    "Ss",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Ss0
 );



dimensionedScalar Re0("Re0", lengthDims, 0.0);
volScalarField Re
(
   IOobject
   (
    "Re",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Re0
 );

// diffusion length
dimensionedScalar lld0("lld0", lengthDims, 0.0);
volScalarField lld
(
   IOobject
   (
    "lld",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, lld0
 );

// diffusion length
dimensionedScalar lsd0("lsd0", lengthDims, 0.0);
volScalarField lsd
(
   IOobject
   (
    "lsd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, lsd0
 );
