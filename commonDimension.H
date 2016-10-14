#include "dimensionSet.H"

/*
 * 1: Mass         kg
 * 2: Length       m
 * 3: Time         s
 * 4: Temperature  K
 * 5: Quantity     mol
 * 6: Current      A
 * 7: Luminous     cd
 */

#ifndef COMMON_DIMENSION_H
#define COMMON_DIMENSION_H
// predefined dimension set
dimensionSet accelerationDimSet(0, 1, -2, 0, 0, 0, 0); //  m / s^-2
dimensionSet nucleationDensityDims(0, -3, 0, 0, 0, 0, 0); // m^-3
dimensionSet dimensionless(0, 0, 0, 0, 0, 0, 0);  
dimensionSet dimensionlessRate(0, 0, -1, 0, 0, 0, 0);  
dimensionSet lengthDims(0, 1, 0, 0, 0, 0, 0); // m
dimensionSet velocity(0, 1, -1, 0, 0, 0, 0); //  m/s
dimensionSet volumeFractionRate(0, 0, -1, 0, 0, 0, 0); // 1/s
dimensionSet phaseDiagramLineSlope(0, 0, 0, 1, 0, 0, 0); // K
dimensionSet diffusionCoeffDims(0, 2, -1, 0, 0, 0, 0); // m^2/s
dimensionSet volumetricEnergy(1, -1, -2, 0, 0, 0, 0);
dimensionSet volumetricEnergyRate(1, -1, -3, 0, 0, 0, 0);
dimensionSet specificHeat(0, 2, -2, -1, 0, 0, 0);
dimensionSet densityDims(1, -3, 0, 0, 0, 0, 0);
dimensionSet temperatureDims(0, 0, 0, 1, 0, 0, 0);
dimensionSet temperatureRateDims(0, 0, -1, 1, 0, 0, 0);
dimensionSet latentHeatDims(0, 2, -2, 0, 0, 0, 0);
dimensionSet thermalConductivityDims(1, 1, -3, -1, 0, 0, 0);
dimensionSet thermalDiffusivityDims(0, 2, -1, 0, 0, 0, 0);
dimensionSet energy(1, 2, -2, 0, 0, 0, 0); //J kg m^2 s-2
dimensionSet enthalpy(energy);
dimensionSet specificEnthalpy(0, 2, -2, 0, 0, 0, 0);
dimensionSet GibbsThomsonCoefficient(0, 1, 0, 1, 0, 0, 0); // m K
dimensionSet areaPerVolumn(0, -1, 0, 0, 0, 0, 0); // m K
#endif
