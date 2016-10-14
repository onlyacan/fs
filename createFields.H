#include "field/macroproperty.H"
#include "field/alloySystemProperty.H"
#include "field/initialFields.H"

// the sequence is not important
// sequence depdence is handled in initialFields.H
#include "field/NSEqn.H"
#include "field/TEqn.H"
#include "field/CsEqn.H"
#include "field/ggEqn.H"
#include "field/geEqn.H"
#include "field/gsEqn.H"
#include "field/ClEqn.H"
#include "field/microDimension.H"


#include "createPhi.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());
