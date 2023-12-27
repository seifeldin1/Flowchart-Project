#include "StartStat.h"

StartStat::StartStat(Point Lcorner) : Statement (Lcorner,"Start")
{}

StartStat::StartStat(ifstream& input): Statement (input)
{}

Statement* StartStat::Copy() 
{
	Statement* copyStart = new StartStat(Point(0, 0)); // will work when other fuctions implemented ///stores a copy of start in copy
	return copyStart;

}

//Draws the ellipse with text="Start"
void StartStat::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse function to draw Start statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}

void StartStat::Save(ofstream& OutFile)
{
	OutFile << "Start" << LeftCorner.x << LeftCorner.y << endl;
}

void StartStat::Load(ifstream& InFile)
{
	InFile >> LeftCorner.x >> LeftCorner.y;
}

//Checks if Start Statement has been clicked on
bool StartStat::IsPointClicked(Point P) const
{
	if ( (P.x >= LeftCorner.x && P.x <= LeftCorner.x + UI.ASSGN_WDTH) && (P.y >= LeftCorner.y && P.y <= LeftCorner.y + UI.ASSGN_HI) )
		return true;
	else
		return false;
}

void StartStat::Simulate(ApplicationManager* pManager)
{

}
StartStat::~StartStat()
{}