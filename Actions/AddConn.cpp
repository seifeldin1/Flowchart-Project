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
	string s = "0";
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
	
	if (s == "y")
		branch = 1;
	else if (s == "n")
		branch = 2;
	else
		branch = 0;
}

void AddConn::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (Src == NULL || Dst == NULL)
	{
		pOut->PrintMessage("Selected empty space. exiting.");
		return;
	}
	if (Src->GetID() == 1)
	{
		pOut->PrintMessage("Can not set source as End. exiting.");
		return;
	}
	if (Dst->GetID() == 0)
	{
		pOut->PrintMessage("Can not set Destination as Start. exiting.");
		return;
	}
	if (Src == Dst)
	{
		pOut->PrintMessage("Selected the same statement. exiting.");
		return;
	}

	Connector* OG_Conn = Src->GetOutConnector(branch);
	if (OG_Conn != NULL)
		pManager->RemoveConnectorFromList(OG_Conn);

	Connector* conn = new Connector(Src, Dst, branch);
	Src->SetOutConnector(conn);
	pManager->AddConnector(conn);

}