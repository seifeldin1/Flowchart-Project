#include "ConditionalState.h"
#include <sstream>

ConditionalState::ConditionalState(Point Lcorner, string LeftHS = "", string RightHS = "", string comparisonOP = "") : Statement(2,true)
{
	LHS = LeftHS;
	Comp_Operator = comparisonOP;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;

	pInConn[200] = { NULL };
	pOutConn[2] = { NULL };
	
	Inlet.x = LeftCorner.x + UI.COND_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.COND_HI;
}

Statement* ConditionalState::Copy()
{
	copyConditional = new ConditionalState(Point(0, 0), ((ConditionalState*)this)->LHS, ((ConditionalState*)this)->RHS, ((ConditionalState*)this)->Comp_Operator);
	return copyConditional;
}

//sets left hand side
void ConditionalState::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

//sets right hand side
void ConditionalState::setRHS(const string &R)
{
	RHS = R;
	UpdateStatementText();
}

//sets Comparison Operator
void ConditionalState::setCompOp(const string &comOp)
{
	Comp_Operator = comOp;
	UpdateStatementText();
}

//This function should be called when LHS or RHS or Comparison operator changes
void ConditionalState::UpdateStatementText()
{
	//Build the statement text: Left handside then Comparison Operator then right handside
	ostringstream T;
	T << LHS << Comp_Operator << RHS;
	Text = T.str();
}

//returns top left corner point of statement
Point ConditionalState::GetLcorner() const
{
	return LeftCorner;
}

//returns (5) which we set to identify that statement is conditional
int ConditionalState::ReturnStatType()
{
	return 5;
}

//Draw the rectangle with text LHS Comp_Operator RHS
void ConditionalState::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus function to draw assignment statement 	
	pOut->DrawRhombus(LeftCorner, UI.COND_WDTH, UI.COND_HI, Text, Selected);
}

//Checks if Conditional Statement has been clicked on
bool ConditionalState::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.COND_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.COND_HI))
		return true;
	else
		return false;
}

//Sets a connector going to the Conditional statement
void ConditionalState::SetInConnector(Connector* incon)
{
	CondInConnCount++;
	pInConn[CondInConnCount] = incon;
}

//Sets a connector coming out from the value assign statement
void ConditionalState::SetOutConnector(Connector* outcon)
{
	CondOutConnCount++;
	pOutConn[CondOutConnCount] = outcon;
}

//Gets connector going to value assign statement
Connector* ConditionalState::GetInConnector() const
{
	for (int i = 0; i < CondInConnCount; i++)
	{
		return pInConn[i];
	}
}

//Gets connector coming out from value assign statement
Connector* ConditionalState::GetOutConnector() const
{
	for (int i = 0; i < CondOutConnCount; i++)
	{
		return pOutConn[i];
	}
}

//returns count of connectors going into conditional statement
int ConditionalState::GetConnInCount() const
{
	return CondInConnCount;
}

string ConditionalState::GetOperator()
{
	if (Comp_Operator == ">")
		return "GREATER";
	else if (Comp_Operator == "<")
		return "SMALLER";
	else if (Comp_Operator == ">=")
		return "GREATER_E";
	else if (Comp_Operator == "<=")
		return "SMALLER_E";
	else if (Comp_Operator == "!=")
		return "NOT_E";
}		

int ConditionalState::GetOutConnCount() const{}

ConditionalState::~ConditionalState()
{
	for (int i = 0; i < CondInConnCount; i++)
	{
		delete pInConn[i];
		CondInConnCount--;
	}
	for (int i = 0; i < CondOutConnCount; i++)
	{
		delete pOutConn[i];
		CondOutConnCount--;
	}
}
