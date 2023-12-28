#include "AddWrite.h"
#include"..\Statements\WriteState.h"

AddWrite::AddWrite(ApplicationManager* pManager) : Action(pManager)
{

}
void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Click to add the write statement");

	pIn->GetPointClicked(P);
	pOut->ClearStatusBar();

	variable = pIn->GetVariable(pOut);


}

void AddWrite::Execute()
{
	ReadActionParameters();

	WriteState* pWrite = new WriteState(P, variable);

	pManager->AddStatement(pWrite);

}