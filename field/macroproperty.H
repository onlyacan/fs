Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
 IOobject
 (
  "transportProperties",
  runTime.constant(),
  mesh,
  IOobject::MUST_READ_IF_MODIFIED,
  IOobject::NO_WRITE
  )
 );



dimensionedScalar rho(transportProperties.lookup("rho"));
dimensionedScalar rho0 = rho;
dimensionedScalar cp(transportProperties.lookup("cp"));
dimensionedScalar k(transportProperties.lookup("k")); // heat conductivity
dimensionedScalar DT = k/(rho0 * cp); // thermal diffusivity
dimensionedScalar L(transportProperties.lookup("L"));
dimensionedScalar Leut(transportProperties.lookup("Leut"));
dimensionedScalar ddt_T0(transportProperties.lookup("ddt_T0")); 

dimensionedScalar betaT(transportProperties.lookup("betaT")); 
dimensionedScalar betaC(transportProperties.lookup("betaC")); 
dimensionedScalar Tref(transportProperties.lookup("Tref")); 
dimensionedScalar Cref(transportProperties.lookup("Cref")); 
