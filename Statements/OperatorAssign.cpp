#include "OperatorAssign.h"
#include <sstream>

OperatorAssign::OperatorAssign(Point Lcorner, string LeftHS, string RightHS) : Statement(1, true)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
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

void OperatorAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}
void OperatorAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}
void OperatorAssign::setRHS1(const string& R1)
{
	RHS1 = R1;
	UpdateStatementText();
}
void OperatorAssign::setRHS2(const string& R2)
{
	RHS2 = R2;
	UpdateStatementText();
}
void OperatorAssign::setArthOp(const string& arthOp)
{
	ArthOp = arthOp;
	UpdateStatementText();
}

//This function should be called when LHS or RHS changes
void OperatorAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS1 << ArthOp << RHS2;
	Text = T.str();
}

//returns top left corner of statement
Point OperatorAssign::GetLcorner() const
{
	return LeftCorner;
}

//returns (7) which we set to identify that statement is End
int OperatorAssign::ReturnStatType()
{
	return 7;
}

//Draw the rectangle with text LHS"="RHS1 Arthiemtic_Operator RHS2
void OperatorAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRectangle(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if Value Assign Statement has been clicked on
bool OperatorAssign::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

//Sets a connector going to the value assign statement
void OperatorAssign::SetInConnector(Connector* incon)
{
	OpAssInConnCount++;
	pInConn[OpAssInConnCount] = incon;
}

//Sets a connector coming out from the value assign statement
void OperatorAssign::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}

//Gets connector going to value assign statement
Connector* OperatorAssign::GetInConnector() const
{
	for (int i = 0; i < OpAssInConnCount; i++)
	{
		return pInConn[i];
	}
}

//Gets connector coming out from value assign statement
Connector* OperatorAssign::GetOutConnector() const
{
	return pOutConn;
}

int OperatorAssign::GetConnInCount() const
{
	return OpAssInConnCount;
}

string OperatorAssign::GetOperator()
{
	if (ArthOp == "+")
		return "PLUS";
	else if (ArthOp == "-")
		return "MINUS";
	else if (ArthOp == "*")
		return "multi";
	else if (ArthOp == "/")
		return "DIVIDE";
}

OperatorAssign::~OperatorAssign()
{
	for (int i = 0; i < OpAssInConnCount; i++)
	{
		delete pInConn[i];
		OpAssInConnCount--;
	}
	delete pOutConn;
}

int OperatorAssign::GetOutConnCount() const {}