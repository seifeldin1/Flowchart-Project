#include "AssignStat.h"
#include <sstream>

AssignStat::AssignStat(Point Lcorner, string LeftHS, string RightHS) : Statement(Lcorner, LeftHS + " = " + RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	// before passing it to the constructor of AssignStat
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet
}

//sets left hand side
void AssignStat::setLHS(string L)
{
	LHS = L;
	UpdateStatementText();
}

//sets right hand side
void AssignStat::setRHS(string R)
{
	OpType T = ValueOrVariable(R);
	switch (T)
	{
	case VALUE_OP:
		type = Value;
		break;
	case VARIABLE_OP:
		type = Variable;
		break;
	case INVALID_OP:
		//add extra tests
		break;
	}

	UpdateStatementText();
}

//This function should be called when LHS or RHS changes
void AssignStat::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

//Draw the rectangle with text LHS"="RHS
void AssignStat::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRectangle(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if Value Assign Statement has been clicked on
bool AssignStat::IsPointClicked(Point P) const
{
	if ( (P.x >=LeftCorner.x && P.x<=LeftCorner.x+UI.ASSGN_WDTH) && (P.y>=LeftCorner.y && P.y<=LeftCorner.y+UI.ASSGN_HI) )
		return true;
	else
		return false;
}

AssignStat::~AssignStat()
{
	/*
	for (int i = 0; i < ValueAssInConnCount; i++)
	{
		delete pInConn[i];
		ValueAssInConnCount--;
	}
	delete pOutConn;
	*/
}