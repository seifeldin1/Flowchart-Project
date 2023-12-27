#include "EndStat.h"

EndStat::EndStat(Point Lcorner) : Statement (Lcorner, "End")
{}

EndStat::EndStat(ifstream& input) : Statement (input)
{}

void EndStat::UpdateStatementText() {}

Statement* EndStat::Copy() {
	Statement* copyEnd = new EndStat(Point(0,0)); // makes a copy of End
	return copyEnd;
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

void EndStat::Save(ofstream& OutFile)
{
	OutFile << "Save" << "" << ID << "" << LeftCorner.x << "" << LeftCorner.y << endl;
}

void EndStat::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y;
}

EndStat::~EndStat()
{
	/*for (int i = 0; i < EndInConnCount; i++)
	{
		delete pInConn[i];
		EndInConnCount--;
	}*/
}