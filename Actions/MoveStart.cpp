#include "MoveStart.h"

MoveStart::MoveStart(ApplicationManager* pM) :Action(pM)
{}

void MoveStart::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click on anywhere to move Start.");
	pIn->GetPointClicked(Lcorner);
}

void MoveStart::Execute()
{
	ReadActionParameters();
	pManager->MoveSt(Lcorner);
}
