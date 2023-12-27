#include "AddWrite.h"

AddWrite::AddWrite(ApplicationManager* pManager) : Action(pManager)
{

}
void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Add Write Class: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	Variable = pIn->GetVariable(pOut);


}

void AddWrite::Execute()
{

}