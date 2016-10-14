/*============================================
all variable related to Navier-Stock equation
==============================================*/

dimensionedScalar nu
(
    "nu",
    dimViscosity,
    transportProperties.lookup("nu")
);


Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


volScalarField rhof_tilde
(
    IOobject
    (
        "rhof_tilde",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhof_tilde0",  dimensionless, 1.0)
);


Info<< "creating gravity acceleration g \n" << endl;

volVectorField g
(
    IOobject
    (
        "g",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh, 
        dimensionedVector ("g0", accelerationDimSet, vector(0.0, -9.8, 0.0))
); 



volScalarField K // Blake-Kozeny Coefficient
(
    IOobject
    (
        "K",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("K0",  dimensionSet(0, 2, 0, 0, 0, 0, 0), 0.0)
);
