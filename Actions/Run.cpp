#include "Run.h"

Run::Run(ApplicationManager* pAppManager, Validate* validate_Act) : Action(pAppManager)
{
	this->validate_Act = validate_Act;
}
void Run::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Run Action : Running The FlowChart");
}

void Run::Execute()
{
	ReadActionParameters();

	// Check That there is a Validation

	if (validate_Act->IsValidated == false)
		validate_Act->Execute();

	// When doing a Validation Before Running and this Validation is False
	if (validate_Act->IsValidated == false)
	{
		pOut->PrintMessage("Run Action : Couldn't Run Because of Errors in Validation");
		return;
	}

	pManager->RunFlow();
	pOut->PrintMessage("Run Action : Program is Running Successfully");
}