dimensionedScalar Cs0("Cs0", C0 * kp);
volScalarField Cs
(
   IOobject
   (
    "Cs",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
   mesh, Cs0
 );


// used only in Cs Equation
volScalarField ad_sd // = Ss * Ds / lsd; 
(
   IOobject
   (
    "ad_sd",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
    mesh, 
    dimensionedScalar("ad_sd0", dimensionSet (0, 0, -1, 0, 0, 0, 0), 0.0)
 );


