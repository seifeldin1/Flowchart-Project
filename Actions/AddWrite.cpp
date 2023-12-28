#include "AddWrite.h"

#include"..\Statements\WriteState.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

AddWrite::AddWrite(ApplicationManager* pManager) : Action(pManager)
{}

void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click to add the write statement");
	pIn->GetPointClicked(Point);
	pOut->PrintMessage("Enter a variable that you want to read");
	variable = pIn->GetVariable(pOut);
}
void AddWrite::Execute()
{
	ReadActionParameters();

	WriteState* pWrite = new WriteState(Point, variable);

	pManager->AddStatement(pWrite);

}