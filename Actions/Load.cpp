#include "Load.h"
Load::Load(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Load::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("write desired save file name:");
	Filename = pIn->GetString(pOut) + ".txt";
}

void Load::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	ifstream input;
	input.open(Filename, ios::in);

	pManager->LoadAll(input);

	pOut->PrintMessage("Loading successful!");
	input.close();
}