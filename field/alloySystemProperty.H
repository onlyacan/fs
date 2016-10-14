IOdictionary alloySystem
(
     IOobject
     (
      "alloySystemProperty",
      runTime.constant(),
      mesh,
      IOobject::MUST_READ_IF_MODIFIED,
      IOobject::NO_WRITE
      )
 );



dimensionedScalar Tl(alloySystem.lookup("Tl"));
dimensionedScalar C0(alloySystem.lookup("C0"));
dimensionedScalar ml(alloySystem.lookup("ml"));
dimensionedScalar Tf("Tf",  Tl - C0 * ml); //eqn [6] C0 = (Tl - Tf) / ml;
dimensionedScalar kp(alloySystem.lookup("kp"));
dimensionedScalar Teut(alloySystem.lookup("Teut"));
dimensionedScalar N(alloySystem.lookup("N")); // nucleation density 
dimensionedScalar Gamma(alloySystem.lookup("Gamma")); // Gibbs-Thomson coefficient (m K)
dimensionedScalar Dl(alloySystem.lookup("Dl")); // diffusion coeff. of B in liquid
dimensionedScalar Ds(alloySystem.lookup("Ds")); // diffusion coeff. of B in Solid
dimensionedScalar alpha_e(alloySystem.lookup("alpha_e")); // growth coeff. eutectic 
dimensionedScalar lambda2(alloySystem.lookup("lambda2")); // secondary arm spacing 

// some calculatoin
dimensionedScalar Ceut("Ceut", (Teut - Tf) / ml); // calculated from eqn[6]
dimensionedScalar Rf("Rf", Foam:: pow(3.0 / (4.0 * PI * N), (1.0/3.0)) );

// output befefore calculation 
Info << Tl << endl
<< C0 << endl
<< ml << endl
<< kp << endl
<< Teut << endl
<< Ceut << endl
<< N << endl
<< Rf << endl;

// prompt and wait for user to check
string s;
cin >> s;
