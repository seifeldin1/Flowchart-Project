#include "AddRead.h"


AddRead::AddRead(ApplicationManager* pAppManager) : Action(pAppManager) {}

void AddRead::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click at any location to add a read statement");
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P);
	pOut->PrintMessage("Enter a variable that you want to read");
	variable = pIn->GetVariable(pOut);
}
void AddRead::Execute() {
	ReadActionParameters();
	
	ReadState* pRead = new ReadState(P, variable);

	pManager->AddStatement(pRead);
}
