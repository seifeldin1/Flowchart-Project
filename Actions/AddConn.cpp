#include "AddConn.h"
#include "..\Statements\ConditionalState.h"
AddConn::AddConn(ApplicationManager* pAppManager) : Action (pAppManager)
{}

void AddConn::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Point p;
	pOut->PrintMessage("Select Source Statement.");
	pIn->GetPointClicked(p);
	string s = 0;
	Src = pManager->GetStatement(p);
	if (dynamic_cast<ConditionalState*>(Src) != NULL)
	{
		pIn->GetPointClicked(p);
		pOut->PrintMessage("Select Connector type (y,n):");
		while (true)
		{
			s = pIn->GetString(pOut);
			if (s == "y" || s == "n")
			{
				break;
			}
			pOut->PrintMessage("incorrect. try again (y,n):");
		}
	}
	pOut->PrintMessage("Select Destination Statement.");
	pIn->GetPointClicked(p);
	Dst = pManager->GetStatement(p);
	if (Src == NULL || Dst == NULL)
	{
		pOut->PrintMessage("Selected empty space exiting");
		return;
	}

	int branch;

	if (s == "y")
		branch = 1;
	else if (s == "n")
		branch = 2;
	else
		branch = 0;
	Connector* conn = new Connector(Src,Dst,branch);
	pManager->AddConnector(conn);
}

void AddConn::Execute()
{}