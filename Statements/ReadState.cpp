#include "ReadState.h"
#include "sstream"

ReadState::ReadState(Point Lcorner, string var = "") : Statement(Lcorner,Text)
{
	Variable = var;
	UpdateStatementText();
	pOutConn = NULL; //no connectors yet going out from statement
	LeftCorner = Lcorner;
}
void ReadState::SetVariable(string var)
{
	Variable = var;
}

//This function should be called when variable changes
void ReadState::UpdateStatementText()
{
	//Build the statement text: Write the Variable
	ostringstream T;
	T << "Read " << Variable;
	Text = T.str();
}

bool ReadState::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

//Draw the Parallelogram
void ReadState::Draw(Output* pOut) const
{
	//Call Output::DrawParralellogram function to draw write statement 
	pOut->DrawParralellogram(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

void ReadState::Save(ofstream& OutFile)
{

}
void ReadState::Load(ifstream& Infile)
{

}
Statement* ReadState::Copy()
{
	Statement* copyRead = new ReadState(Point(0, 0), ((ReadState*)this)->Variable);
	return copyRead;
}
void ReadState::Simulate(ApplicationManager* pManager)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (Variable != "")
	{
		pOut->PrintMessage("Enter The Value of "+Variable);
		Value = pIn->GetValue(Output * pO);
		pManager->AddIntVariable(Variable, Value);
	}
}

ReadState::~ReadState() {}