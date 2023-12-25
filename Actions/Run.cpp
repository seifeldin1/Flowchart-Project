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

	if (validate_Act->IsValidated == false)
	{
		validate_Act->Execute();
	}

	pManager->RunFlow();
	pOut->PrintMessage("Run Action : Program is Running Successfully");
}