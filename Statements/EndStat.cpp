#include "EndStat.h"

EndStat::EndStat(Point Lcorner) : Statement (Lcorner,Text)
{
	Text = "End";
}

void EndStat::UpdateStatementText() {}

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
void EndStat::Simulate()
{

}
void EndStat::Save(ofstream& OutFile)
{

}
void EndStat::Load(ifstream& Infile)
{

}
Statement* EndStat::Copy() 
{
	Statement* copyEnd = new EndStat(Point(0, 0)); // makes a copy of End
	return copyEnd;
}
EndStat::~EndStat() {}