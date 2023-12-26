#include "EndState.h"

EndState::EndState(Point Lcorner) : Statement (0,true)
{
	Text = "End";
	LeftCorner = Lcorner;
	pInConn[200] = { NULL };

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

}

void EndState::UpdateStatementText() {}

Statement* EndState::Copy() {
	copyEnd = new EndState(Point(0, 0)); // makes a copy of End
	return copyEnd;
}

//returns Left corner point of statement
Point EndState::GetLcorner() const
{
	return LeftCorner;
}

//returns (1) which we set to identify that statement is End
int EndState::ReturnStatType()
{
	return 1;
}

//Draws the ellipse with text="End"
void EndState::Draw(Output *pOut) const
{
	//Call Output::DrawEllipse function to draw End statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if End Statement has been clicked on
bool EndState::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

//sets a connector going to end statement
void EndState::SetInConnector(Connector* incon)
{
	EndInConnCount++;
	pInConn[EndInConnCount] = incon;
}

//returns all connector going to end statement
Connector* EndState::GetInConnector() const
{
	for (int i = 0; i < EndInConnCount; i++)
	{
		return pInConn[i];
	}
}

int EndState::GetConnInCount() const
{
	return EndInConnCount;
}

EndState::~EndState()
{
	for (int i = 0; i < EndInConnCount; i++)
	{
		delete pInConn[i];
		EndInConnCount--;
	}
}

void EndState::SetOutConnector(Connector* outcon){}
Connector* EndState::GetOutConnector() const{}
int EndState::GetConnOutCount() const{}