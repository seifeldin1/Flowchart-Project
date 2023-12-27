#include "WriteState.h"
#include <sstream>

WriteState::WriteState(Point Lcorner, string var) : Statement(Lcorner,Text)
{
	Variable = var;
	UpdateStatementText();
	pOutConn = NULL; //no connectors yet going out from statement
	LeftCorner = Lcorner;
}

void WriteState::SetVariable(string var)
{
	Variable = var;
	UpdateStatementText();
}

//This function should be called when variable changes
void WriteState::UpdateStatementText()
{
	//Build the statement text: Write the Variable
	ostringstream T;
	T << "Write " << Variable;
	Text = T.str();
}

//Draw the Parallelogram
void WriteState::Draw(Output* pOut) const
{
	//Call Output::DrawParralellogram function to draw write statement 
	pOut->DrawParralellogram(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if Write Statement has been clicked on
bool WriteState::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

void WriteState::Simulate()
{

}
void WriteState::Save(ofstream& OutFile)
{

}
void WriteState::Load(ifstream& Infile)
{

}
Statement* WriteState::Copy() 
{
	Statement* copyWrite = new WriteState(Point(0, 0), ((WriteState*)this)->Variable);
	return copyWrite;
}
WriteState::~WriteState() {}