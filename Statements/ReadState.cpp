#include "ReadState.h"
#include "sstream"

ReadState::ReadState(Point Lcorner, string var) : Statement(Lcorner, "Read " + var)
{
	Variable = var;
	UpdateStatementText();
}

ReadState::ReadState(ifstream& input) : Statement (input)
{
	Load(input);
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

void ReadState::Simulate()
{

}

void ReadState::Save(ofstream& OutFile)
{
	OutFile << "Read" << " " << ID << " " << Variable << " " << LeftCorner.x << " " << LeftCorner.y << endl;
}
void ReadState::Load(ifstream& Infile)
{
	Infile >> ID >> Variable >> LeftCorner.x >> LeftCorner.y;	
}
Statement* ReadState::Copy()
{
	Statement* copyRead = new ReadState(Point(0, 0), ((ReadState*)this)->Variable);
	return copyRead;
}

ReadState::~ReadState() {}