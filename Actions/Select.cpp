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

	Statement* StatCheck = pManager->GetStatement(Position);
	Connector* ConnCheck = pManager->GetConnector(Position);
	if (StatCheck)
	{
		if (StatCheck->IsSelected() == true)
		{
			StatCheck->SetSelected(false);
			pManager->SetSelectedStatement(NULL);
			return;
		}
		else
		{
			StatCheck->SetSelected(true);
			pManager->SetSelectedStatement(StatCheck);
			(pManager->GetSelectedStatement())->SetSelected(false);
			return;
		}
	}
	else if (ConnCheck)
	{
		if (ConnCheck->IsSelected() == true)
		{
			ConnCheck->SetSelected(false);
			pManager->SetSelectedConnector(NULL);
			return;
		}
		else
		{
			ConnCheck->SetSelected(true);
			pManager->SetSelectedConnector(NULL);
			(pManager->GetSelectedStatement())->SetSelected(false);
			return;
		}
	}
}