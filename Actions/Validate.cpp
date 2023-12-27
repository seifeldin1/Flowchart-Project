#include "Validate.h"

Validate(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void Validate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Validate : Checking the FlowChart");

}
void Validate::Execute()
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

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

	Validate_Status = pManager->CheckNumConn();
	if (Validate_Status == false)
	{
		pOut->PrintMessage("Error : A Conditional Statement Must Have Two Output Connectors Only");
		return;
	}

	Validate_Status = true;
}
bool Validate::IsValidated()
{
	return Validate_Status;
}