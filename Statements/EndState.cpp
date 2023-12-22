#include "EndState.h"

EndState::EndState(Point leftcorner)
{
	LeftCorner = leftcorner;
}

void EndState::Draw(Output *pOut) const
{
	//Call Output::DrawEllipse function to draw End statement
	pOut->DrawEllipse(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, "Start");
}

void EndState::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
}

bool EndState::IsClicked(Point p) const
{
	
}

bool EndState::IsConnected() const
{

}