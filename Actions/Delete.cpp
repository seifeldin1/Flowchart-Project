#include "Delete.h"
#include "..\Statements\StartStat.h"
#include "..\Statements\ReadState.h"
#include "..\Statements\EndStat.h"
#include "..\Statements\ConditionalState.h"
#include "..\Statements\AssignStat.h"
#include "..\Statements\WriteState.h"
Delete::Delete(ApplicationManager* pAppManager) :Action(pAppManager) {}

void Delete::ReadActionParameters() 
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select a statement or connector to be deleted");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void Delete::Execute() 
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	Statement* Statdel = pManager->GetStatement(Position);
	Connector* Conndel = pManager->GetConnector(Position);
	if (Statdel)
	{
		if (Statdel->IsSelected() == false)
		{
			Statdel->SetSelected(true);
			Statement* Temp = Statdel;
			if (Temp->GetType() == 3)
			{
				Point des;
				des.x = Position.x + UI.COND_WDTH / 2;
				des.y = Position.y;
				if ((pManager->GetConnector(des))->getDstStat() == Temp)
					pManager->RemoveConnectorFromList(pManager->GetConnector(des));
				pManager->RemoveStatementFromList(Statdel);
			}
			else
			{
				Point des;
				des.x = Position.x + UI.ASSGN_WDTH / 2;
				des.y = Position.y;
				if ((pManager->GetConnector(des))->getDstStat() == Temp)
					pManager->RemoveConnectorFromList(pManager->GetConnector(des));
				pManager->RemoveStatementFromList(Statdel);
			}
		}
	}
	else if (Conndel)
	{
		if (Conndel->IsSelected() == false)
		{
			Conndel->SetSelected(false);
			Connector* Temp = Conndel;
			pManager->RemoveConnectorFromList(Conndel);
			pManager->SetSelectedConnector(NULL);
			return;
		}
	}
}