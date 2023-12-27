#include "MoveEnd.h"


MoveEnd::MoveEnd(ApplicationManager* pM) : Action(pM)
{}

void MoveEnd::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click on anywhere to move End.");
	pIn->GetPointClicked(Lcorner);
}

void MoveEnd::Execute()
{
	ReadActionParameters();
	pManager->MoveEnd(Lcorner);
}
