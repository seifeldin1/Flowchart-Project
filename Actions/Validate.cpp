#include "Validate.h"
void Validate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Validate : Checking the FlowChart");

}
void Validate::Execute()
{
	ReadActionParameters();

	Validate_Status = pManager->CheckStartEnd();

	if (Validate_Status == false)
	{
		pOut->PrintMessage("Error : Must Start With One Start and One End Exactly");
		return;
	}

	Validate_Status = pManager->CheckConnections();
	if (Validate_Status == false)
	{
		pOut->PrintMessage("Error : Conncetions Are Wrong");
		return;
	}

	Validate_Status = pManager->CheckVariableInit();
	if (Validate_Status == false)
	{
		pOut->PrintMessage("Error : A Variable is Used Before Being Intialized");
		return;
	}
}
bool Validate::IsValidated()
{
	return Validate_Status;
}