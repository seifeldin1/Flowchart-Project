#include "Save.h"


Save::Save(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Save::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("write desired save file name (include .txt at the end):");
	Filename = pIn->GetString(pOut);
}

void Save::Execute()
{
	ReadActionParameters();

	ofstream Output;
	Output.open(Filename, ios::trunc);

	int Listsize;

	Statement** Statlist = pManager->GetStatsInfo(Listsize);
	Output << "Statments:" << endl;
	for (int i = 0; i < Listsize; i++)
	{
		//Statlist[i]->Save(Output);  //remove comment once overloaded
	}

	Connector** Connlist = pManager->GetConnsInfo(Listsize);
	Output << "Connectors:" << endl;
	for (int i = 0; i < Listsize; i++)
	{
		Connlist[i]->Save(Output);
	}


	Output.close();
}
