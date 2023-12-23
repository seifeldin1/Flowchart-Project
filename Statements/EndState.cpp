#include "EndState.h"

EndState::EndState(Point Lcorner)
{
	Text = "End";
	LeftCorner = Lcorner;
	pInConn = NULL; //no connectors yet going to end statement
}

void EndState::UpdateStatementText() {}

//returns (1) which we set to identify that statement is End
int EndState::ReturnStatType()
{
	return 1;
}

//Draws the ellipse
void EndState::Draw(Output *pOut) const
{
	//Call Output::DrawEllipse function to draw End statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, "End");
}

//Checks if End Statement has been clicked on
bool EndState::IsPointClicked(Point P) const
{
	if (P.x <= UI.ASSGN_WDTH && P.y <= UI.ASSGN_HI)
		return true;
	else
		return false;
}

//Checks if there exists a connector going to End Statements
bool EndState::IsConnected() const
{
	Point P1=pInConn->getEndPoint(); //Gets end point of connector going to end statement
	if (Inlet.x == P1.x && Inlet.y == P1.y)
		return true;
	else
		return false;
}

//Sets a connector to go the end statement
void EndState::SetConnector(Connector* con)
{
	Inlet= con->getEndPoint();
}