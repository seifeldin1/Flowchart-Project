#include "Select.h"
Select::Select(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Select/Unselect Action: Click to select or unselect the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void Select::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Statement* StatCheck = pManager->GetStatement(Position);
	Connector* ConnCheck = pManager->GetConnector(Position);
	if (StatCheck)
	{
		if (StatCheck->IsSelected() == false)
		{
			StatCheck->SetSelected(true);
			Statement* Temp = StatCheck;
			pManager->AddStatement(Temp);
			pManager->RemoveStatementFromList(StatCheck);
			Temp->Draw(pOut);
			pManager->SetSelectedStatement(Temp);
			return;
		}
		else
		{
			StatCheck->SetSelected(false);
			Statement* Temp = StatCheck;
			pManager->AddStatement(Temp);
			pManager->RemoveStatementFromList(StatCheck);
			Temp->Draw(pOut);
			pManager->SetSelectedStatement(NULL);
			return;
		}
	}
	else if (ConnCheck)
	{
		if (ConnCheck->IsSelected() == false)
		{
			ConnCheck->SetSelected(false);
			Connector* Temp = ConnCheck;
			pManager->AddConnector(Temp);
			pManager->RemoveConnectorFromList(ConnCheck);
			Temp->Draw(pOut);
			pManager->SetSelectedConnector(NULL);
			return;
		}
		else
		{
			ConnCheck->SetSelected(true);
			Connector* Temp = ConnCheck;
			pManager->AddConnector(Temp);
			pManager->RemoveConnectorFromList(ConnCheck);
			Temp->Draw(pOut);
			pManager->SetSelectedConnector(Temp);
			(pManager->GetSelectedStatement())->SetSelected(false);
			return;
		}
	}
}