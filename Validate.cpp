#include "Validate.h"
void Validate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Validate : Checking the FlowChart");

}
void Validate::Execute()
{
	ReadActionParameters();

	// Checking For Start And End Statements
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
}
bool Validate::IsValidated()
{
	return Validate_Status;
}