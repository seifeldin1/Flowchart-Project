#include "AddStart.h"

AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager){}

void AddStart::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click at any location to add a start statement");
}
void AddStart::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P);
	if (/*P.y <= UI.height - /*num*/ /* && P.y >= UI.*/) 
	{

	}
	else {
		Output* pOut;
		pOut->PrintMessage("OOPS! You can't draw here.");
	}
}
