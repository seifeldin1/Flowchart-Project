#include "EndStat.h"

EndStat::EndStat(Point Lcorner) : Statement ()
{
	Text = "End";
}

void EndStat::UpdateStatementText() {}

Statement* EndStat::Copy() {
	copyEnd = new EndStat(Point(0, 0)); // makes a copy of End
	return copyEnd;
}

//returns Left corner point of statement
Point EndStat::GetLcorner() const
{
	return LeftCorner;
}

//returns (1) which we set to identify that statement is End
int EndStat::ReturnStatType()
{
	return 1;
}

//Draws the ellipse with text="End"
void EndStat::Draw(Output *pOut) const
{
	//Call Output::DrawEllipse function to draw End statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if End Statement has been clicked on
bool EndStat::IsPointClicked(Point P) const
{
	if ((P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI))
		return true;
	else
		return false;
}

//sets a connector going to end statement
void EndStat::SetInConnector(Connector* incon)
{
	EndInConnCount++;
	pInConn[EndInConnCount] = incon;
}

//returns all connector going to end statement
Connector* EndStat::GetInConnector() const
{
	for (int i = 0; i < EndInConnCount; i++)
	{
		return pInConn[i];
	}
}

int EndStat::GetConnInCount() const
{
	return EndInConnCount;
}

EndStat::~EndStat()
{
	for (int i = 0; i < EndInConnCount; i++)
	{
		delete pInConn[i];
		EndInConnCount--;
	}
}

void EndStat::SetOutConnector(Connector* outcon){}
Connector* EndStat::GetOutConnector() const{}
int EndStat::GetConnOutCount() const{}