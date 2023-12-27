#include "ConditionalState.h"
#include <sstream>

ConditionalState::ConditionalState(Point Lcorner, string lhs = "", string rhs = "", string oper = "") : Statement(Lcorner, lhs + " " + oper + " " + rhs)
{
	LHS = lhs;
	Operator = oper;
	RHS = rhs;

	UpdateStatementText();


	Yconn = NULL;
	Nconn = NULL;
}

Statement* ConditionalState::Copy()
{
	Statement* copyConditional = new ConditionalState(Point(0, 0), ((ConditionalState*)this)->LHS, ((ConditionalState*)this)->RHS, ((ConditionalState*)this)->Operator);
	return copyConditional;
}

//sets left hand side
void ConditionalState::setLHS(string L)
{
	LHS = L;
	UpdateStatementText();
}

//sets right hand side
void ConditionalState::setRHS(string R)
{
	RHS = R;
	UpdateStatementText();
}

//sets Comparison Operator
void ConditionalState::setOp(string comOp)
{
	Operator = comOp;
	UpdateStatementText();
}

//This function should be called when LHS or RHS or Comparison operator changes
void ConditionalState::UpdateStatementText()
{
	Text = LHS + " " + Operator + " " + RHS;
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

//Sets a connector coming out from the value assign statement
void ConditionalState::SetOutConnector(Connector* con, bool isYconn)
{
	if (isYconn)
		Yconn = con;
	else
		Nconn = con;
}

//Gets connector coming out from value assign statement
Connector* ConditionalState::GetOutConnector(int branch) const
{
	if (branch == 1)
		return Yconn;
	else if (branch == 2)
		return Nconn;
}

void ConditionalState::Save(ofstream& OutFile)
{
	OutFile << "CondStat" << ID << " " << LeftCorner.x << " " << LeftCorner.y << " " << LHS << " " << Operator << " " << RHS << endl;
}

void ConditionalState::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> LHS >> Operator >> RHS;
	UpdateStatementText();
}

void ConditionalState::Simulate(ApplicationManager* pManager)
{
	// string LHS; //Left Handside of the assignment (name of a variable)
	// string Operator;
	// string RHS;
	double D1, D2;

	if (IsValue(LHS))
		D1 = atof(LHS);
	else
		D1 = pManager->ReturnValue();

	if (IsValue(RHS))
		D2 = atof(RHS);
	else
		D2 = pManager->ReturnValue();

	if (Operator == ">")
	{
		if (D1 > D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
	else if (Operator == ">=")
	{
		if (D1 >= D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
	else if (Operator == "<")
	{
		if (D1 < D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
	else if (Operator == "<=")
	{
		if (D1 <= D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
	else if (Operator == "==")
	{
		if (D1 == D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
	else if (Operator == "!=")
	{
		if (D1 != D2)
			ResultConn = Yconn;
		else
			ResultConn = Nconn;
		return;
	}
}
/*
string ConditionalState::GetOperator()
{
	if (Operator == ">")
		return "GREATER";
	else if (Operator == "<")
		return "SMALLER";
	else if (Operator == ">=")
		return "GREATER_E";
	else if (Operator == "<=")
		return "SMALLER_E";
	else if (Operator == "!=")
		return "NOT_E";
}		
*/

ConditionalState::~ConditionalState() {}
