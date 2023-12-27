#include "AddEnd.h"

AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager) {}

void AddEnd::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click at any location to add an end statement");
}
void AddEnd::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P);
	if (/*P.y <= UI.height - /*num*/ /* && P.y >= UI.*/) {

	}
	else {
		Output* pOut;
		pOut->PrintMessage("OOPS! You can't draw here.");
	}
}
