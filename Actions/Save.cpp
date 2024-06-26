#include "Save.h"


Save::Save(ApplicationManager* pAppManager):Action(pAppManager)
{}

void Save::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("write desired save file name:");
	Filename = pIn->GetString(pOut)+ ".txt";
}

void Save::Execute()
{
	ReadActionParameters();

	ofstream Output;
	Output.open(Filename, ios::trunc | ios::out);
	
	pManager->SaveAll(Output);

	Output.close();
}