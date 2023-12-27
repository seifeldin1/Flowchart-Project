#include "ReadState.h"
#include "sstream"

ReadState::ReadState(Point Lcorner, string var = "") : Statement(Lcorner, )
{
	Variable = var;
	UpdateStatementText();
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

Point ReadState::GetLcorner() const
{
	return LeftCorner;
}
//returns (3) which we set to identify that statement is Read
int ReadState::ReturnStatType()
{
	return 3;
}
//Draw the Parallelogram
void ReadState::Draw(Output* pOut) const
{
	//Call Output::DrawParralellogram function to draw write statement 
	pOut->DrawParralellogram(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
bool ReadState::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}
void ReadState::SetInConnector(Connector* incon)
{
	ReadInConnCount++;
	pInConn[ReadInConnCount];
}
void ReadState::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}
Connector* ReadState::GetInConnector() const
{
	for (int i = 0; i < ReadInConnCount; i++)
	{
		return pInConn[i];
	}
}
Connector* ReadState::GetOutConnector() const
{
	return pOutConn;
}
int ReadState::GetConnInCount() const {  };

int ReadState::GetConnOutCount() const {}

Statement* ReadState::Copy()
{
	Statement* copyRead = new ReadState(Point(0, 0), ((ReadState*)this)->Variable);
	return copyRead;
}

ReadState::~ReadState()
{
	/*for (int i = 0; i < ReadInConnCount; i++)
	{
		delete pInConn[i];
		ReadInConnCount--;
	}
	delete pOutConn;*/
}