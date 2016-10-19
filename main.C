#include "fvCFD.H"
#include "pimpleControl.H"
#include "fixedFluxPressureFvPatchScalarField.H"
#include "fvIOoptionList.H"


int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"

    pimpleControl pimple(mesh);

    #include "commonDimension.H"
    #include "global.H" // some global constant
    #include "createFields.H"
    #include "numericalVars.H"
    #include "createFvOptions.H" // from openFOAM template
    #include "init.H"

    #include "initContinuityErrs.H"
    #include "outputfile.H"
    output << "# fields" << endl;
    int micoCalcLoopCounter = 0;
    int TLoopCounter = 0;

    Info<< "\nStarting time loop\n" << endl;
    long timeLevel = 0;

    while (runTime.loop())
    {
        timeLevel ++;
        Info << "Time = " << runTime.timeName() << nl << endl;
        #include "CourantNo.H"
        
        while(pimple.loop())
        {
            // Momentum predictor
            #include "eqn/pimple/UEqn.H"
            
            // --- PISO loop
            #include "pimpleLoop.H"
        
            // other equations
            #include "TLoop.H" 
        }
        
        runTime.write();

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;

        // some numerical information
        numericLog << timeLevel 
                   << " " << TLoopCounter 
                   << " " << micoCalcLoopCounter 
                   << "\n" << endl;
        if (timeLevel % 50 == 1) numericLog << std::flush;
    }

    output.close();
    numericLog.close();
    // Info<< "End and normal exit\n" << endl;

    return 0;
}


// ************************************************************************* //
