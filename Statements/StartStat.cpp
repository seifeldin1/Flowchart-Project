#include "StartStat.h"

StartStat::StartStat(Point Lcorner) : Statement (1,false)
{
	Text = "Start";
	LeftCorner = Lcorner;
	pOutConn = NULL ; //no connector yet coming from start statement

	Outlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Outlet.y = LeftCorner.y + UI.COND_HI;
}

void StartStat::UpdateStatementText() {}

Statement* StartStat::Copy() 
{
	Statement* copyStart = new StartStat(Point(0, 0)); // will work when other fuctions implemented ///stores a copy of start in copy
	return copyStart;

}

//returns top left corner of statement
Point StartStat::GetLcorner() const
{
	return LeftCorner;
}

//returns (0) which we set to identify that statement is Start
int StartStat::ReturnStatType()
{
	return 0;
}

//Draws the ellipse with text="Start"
void StartStat::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse function to draw Start statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

//Checks if Start Statement has been clicked on
bool StartStat::IsPointClicked(Point P) const
{
	if ( (P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI) )
		return true;
	else
		return false;
}

//Sets a connector going out from the start statement
void StartStat::SetOutConnector(Connector* outcon)
{
	pOutConn = outcon;
}

//Gets connector going out from start statement
Connector *StartStat::GetOutConnector() const
{
	return pOutConn;
}

StartStat::~StartStat()
{
	delete pOutConn;
}

void StartStat::SetInConnector(Connector* incon){}
Connector* StartStat::GetInConnector() const{}
int StartStat::GetConnInCount() const{}
int StartStat::GetConnOutCount() const{}