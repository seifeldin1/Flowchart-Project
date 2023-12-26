#include "VariableAssign.h"
#include <sstream>

VariableAssign::VariableAssign(Point Lcorner, string LeftHS, string RightHS) : Statement(1, true)
{
	// Note: The LeftHS and RightHS should be validated inside (AddVariableAssign) action
	// before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pInConn[200] = { NULL };
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

//sets left hand side
void VariableAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

//sets right hand side
void VariableAssign::setRHS(const string &R)
{
	RHS = R;
	UpdateStatementText();
}

//This function should be called when LHS or RHS changes
void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

//returns top left corner of statement
Point VariableAssign::GetLcorner() const
{
	return LeftCorner;
}

//returns (6) which we set to identify that statement is Variable Assign
int VariableAssign::ReturnStatType()
{
	return 6;
}

//Draw the rectangle with text LHS"="RHS
void VariableAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRectangle(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if Value Assign Statement has been clicked on
bool VariableAssign::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

//Sets a connector going to the value assign statement
void VariableAssign::SetInConnector(Connector* incon)
{
	VarAssInConnCount++;
	pInConn[VarAssInConnCount] = incon;
}

//Sets a connector coming out from the value assign statement
void VariableAssign::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}

//Gets connector going to value assign statement
Connector* VariableAssign::GetInConnector() const
{
	for (int i = 0; i < VarAssInConnCount; i++)
	{
		return pInConn[i];
	}
}

//Gets connector coming out from value assign statement
Connector* VariableAssign::GetOutConnector() const
{
	return pOutConn;
}

int VariableAssign::GetConnInCount() const
{
	return VarAssInConnCount;
}

VariableAssign::~VariableAssign()
{
	for (int i = 0; i < VarAssInConnCount; i++)
	{
		delete pInConn[i];
		VarAssInConnCount--;
	}
	delete pOutConn;
}

int VariableAssign::GetOutConnCount() const {}