dimensionedScalar gs0("gs0", dimensionless, 1e-7);
dimensionedScalar gd0("gd0", dimensionless, 0.0);
dimensionedScalar gg0("gg0", gs0 + gd0);
dimensionedScalar gl0("gl0", 1.0 - gg0);
dimensionedScalar gf0("gf0", gd0 + gl0);
