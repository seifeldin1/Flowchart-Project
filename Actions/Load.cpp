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

	ifstream input;
	input.open(Filename, ios::in);

	pManager->LoadAll(input);

	input.close();
}