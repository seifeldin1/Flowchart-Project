#include "ValueAssign.h"
#include <sstream>

using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	// before passing it to the constructor of ValueAssign
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

//sets left hand side
void ValueAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

//sets right hand side
void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}

//returns top left corner of statement
Point ValueAssign::GetLcorner() const
{
	return LeftCorner;
}

//returns Inlet point
Point ValueAssign::GetInlet() const
{
	return Inlet;
}

//returns Outlet point
Point ValueAssign::GetOutlet() const
{
	return Outlet;
}

//returns (2) which we set to identify that statement is End
int ValueAssign::ReturnStatType()
{
	return 2;
}

//Draw the rectangle with text LHS"="RHS
void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRectangle(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}

//Checks if Value Assign Statement has been clicked on
bool ValueAssign::IsPointClicked(Point P) const
{
	if ( (P.x >=LeftCorner.x && P.x<=LeftCorner.x+UI.ASSGN_WDTH) && (P.y>=LeftCorner.y && P.y<=LeftCorner.y+UI.ASSGN_HI) )
		return true;
	else
		return false;
}

//Sets a connector going to the value assign statement
void ValueAssign::SetInConnector(Connector* incon)
{
	ValueAssInConnCount++;
	pInConn[ValueAssInConnCount] = incon;
}

//Sets a connector coming out from the value assign statement
void ValueAssign::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}

//Gets connector going to value assign statement
Connector* ValueAssign::GetInConnector() const
{
	for (int i = 0; i < ValueAssInConnCount; i++)
	{
		return pInConn[i];
	}
}

//Gets connector coming out from value assign statement
Connector* ValueAssign::GetOutConnector() const
{
	return pOutConn;
}

int ValueAssign::GetConnInCount() const
{
	return ValueAssInConnCount;
}

ValueAssign::~ValueAssign()
{
	for (int i = 0; i < ValueAssInConnCount; i++)
	{
		delete pInConn[i];
	}
	delete pOutConn;
}
