#include "AddConn.h"
#include "../Statements/ConditionalState.h"
AddConn::AddConn(ApplicationManager* pAppManager) : Action (pAppManager)
{}

void AddConn::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point p;
	pOut->PrintMessage("Select Source Statement.");
	pIn->GetPointClicked(p);
	string s;
	Src = pManager->GetStatement(p);
	if (dynamic_cast<ConditionalState*>(Src) != NULL)
	{
		pOut->PrintMessage("Select Connector type (y,n):");
		s = pIn->GetString(pOut);

	}
	pOut->PrintMessage("Select Destination Statement.");
	pIn->GetPointClicked(p);
	Dst = pManager->GetStatement(p);
}

