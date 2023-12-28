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
	pIn->GetPointClicked(Point);


	pOut->PrintMessage("Enter Variable to Write:");
	variable = pIn->GetVariable(pOut);
}

void AddWrite::Execute()
{
	ReadActionParameters();

	WriteState* pWrite = new WriteState(Point, variable);

	pManager->AddStatement(pWrite);

}