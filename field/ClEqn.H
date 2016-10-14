dimensionedScalar Cl0("Cs0", C0);
volScalarField Cl
(
   IOobject
   (
    "Cl",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
    ),
   mesh
 );


// some temp field
volScalarField ad_ld // = Se * Dl / lld; 
(
   IOobject
   (
    "ad_ld",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::AUTO_WRITE
    ),
    mesh, 
    dimensionedScalar("ad_ld0", dimensionSet (0, 0, -1, 0, 0, 0, 0), 0.0)
 );

/* modify the flux field method for the flux of (a U)
where a is a coefficient scalarVolField */
surfaceScalarField glgf_phi
(
    IOobject
    (
        "glgf_phi",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    linearInterpolate(U) & mesh.Sf()
);
