// updat the tip growth velocity w
// some fields doesn't have to be put into the cell loop


// cell-loop
forAll(T, i){
    // condition Teut < T < Tl && gs < 1.0
    if (gs[i] < 1.0){
        // before solidification T > Tl
        if (T[i] >= Tl.value()){
            Omega[i] = 0.0; 
            ivIvr[i] = 0.0;
            ddt_ge[i] = 0.0;
            smarker[i] = 0.0;
        }

        // in the primary solidification range
        else if (Teut.value() < T[i] && T[i] < Tl.value()){
            Omega[i] = (Cl_star[i] - Cl[i])/(Cl_star[i] * (1.0 - kp.value())); 
            if (Omega[i] <= 0 || Omega[i] >= 1){
                Info << "cell" << i << ": " << "Cl_star = " << Cl_star[i] << ", Cl = "<< Cl[i] << endl;
                //Omega.prevIter() 
                Info << "previous iter: "  << "Cl = "<< Cl.prevIter()[i] << endl;
                Info << "old time: "  << "Cl = "<< Cl.oldTime()[i] << endl;
                Info << "dep values:" << "gl " << gl[i] << ", ddt_gl " << ddt_gl[i] << ", Cl " << Cl[i] << "Cl_star" << Cl_star[i] << "Se = " << Se[i] << "wne" << wne[i] << "Omega=" << Omega[i] << endl;
                Info << "old values:" << "gl " << gl.oldTime()[i] << ", ddt_gl " << ddt_gl.oldTime()[i] << ", Cl " << Cl.oldTime()[i] << "Cl_star" << Cl_star.oldTime()[i] << "Se = " << Se.oldTime()[i] << "wne="<< wne.oldTime()[i] << " Omega " << Omega.oldTime()[i]<< endl;
                Info << "Programm end because " << "Omega[" << i << "] = " << Omega[i] << endl;
                output.close();
                return 0;
            } 
            ivIvr[i] = 0.4567 * Foam:: pow((Omega[i] / (1.0 - Omega[i])) , 1.195);
            ddt_ge[i] = 0.0;
            smarker[i] = 1.0;
        }

        // in the eutectic solidification range
        else if (T[i] <= Teut.value()){
            Omega[i] = 0.0; 
            ivIvr[i] = 0.0;
            smarker[i] = 2.0;
            // primary solidification is supressed 
            // eutectid solidification is on
            if (ge[i] + gs[i] <= 1.0){
                ddt_ge[i] = alpha_e.value() * (T[i] - Teut.value()) * (T[i] - Teut.value());
            }
            else{
                ddt_ge[i] = 0.0;
            }

        }

    }

    // solidification already full 
    else{
        Omega[i] = 0.0; // no usaful only for post-processing
        ivIvr[i] = 0.0;
        ddt_ge[i] = 0.0;
        smarker[i] = -1.0;
    }
}

wne = (Dl * ml * (kp-1.0) * Ce / (PI * PI * Gamma) ) * (ivIvr * ivIvr);
Info << "dendrite tip velocity updated" << endl;
wne.relax();

// code for testing

/*
  Info << "T" << T[i] << " Omega " << Omega[i]
  << " Cl_star " << Cl_star[i] 
  << " Cl " << Cl[i] 
  << " Csd " << Csd[i] << endl;
*/

