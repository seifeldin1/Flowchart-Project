#include "AddRead.h"

#include"..\Statements\ReadState.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

AddRead::AddRead(ApplicationManager* pAppManager) : Action(pAppManager) 
{}

void AddRead::ReadActionParameters() 
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click at any location to add a read statement");
	pIn->GetPointClicked(Point);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Enter a variable that you want to read");
	pIn->GetPointClicked(P);
	variable = pIn->GetVariable(pOut);
}
void AddRead::Execute() 
{
	ReadActionParameters();
	
	ReadState* pRead = new ReadState(Point, variable);

	pManager->AddStatement(pRead);
}
