#include "WriteState.h"
#include <sstream>

WriteState::WriteState(Point Lcorner, string var) : Statement(1,true)
{
	
	Variable = var;
	UpdateStatementText();
	pInConn[200] = { NULL }; //no connectors yet going into statement
	pOutConn = NULL; //no connectors yet going out from statement
	LeftCorner = Lcorner;
	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.x = LeftCorner.x + UI.ASSGN_HI;
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

//returns top left corner of statement
Point WriteState::GetLcorner() const
{
	return LeftCorner;
}

Statement* WriteState::Copy() {
	Statement* copyWrite = new WriteState(Point(0, 0), ((WriteState*)this)->Variable);
	return copyWrite;
}
//returns (4) which we set to identify that statement is Write
int WriteState::ReturnStatType()
{
	return 4;
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

//Sets a connector going to the value assign statement
void WriteState::SetInConnector(Connector* incon)
{
	WriteInConnCount++;
	pInConn[WriteInConnCount] = incon;
}

//Sets a connector coming out from the value assign statement
void WriteState::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}

//Gets connector going to write statement
Connector* WriteState::GetInConnector() const
{
	for (int i = 0; i < WriteInConnCount; i++)
	{
		return pInConn[i];
	}
}

//Gets connector coming out from write statement
Connector* WriteState::GetOutConnector() const
{
	return pOutConn;
}

int WriteState::GetConnInCount() const
{
	return WriteInConnCount;
}

int WriteState::GetConnOutCount() const{}