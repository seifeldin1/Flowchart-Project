#pragma once
#include "Statement.h"

class EndState
{
	private:
		Point Inlet;       //A point where connections enters this statement 
		Point LeftCorner;  //top left corner of the statement block.
		
		Connector *pInConn; //End Stat. has one Connector from previous statement

		virtual void UpdateStatementText();
	public:
		EndState(Point leftcorner);

		virtual void Draw(Output *pOut) const;
		virtual bool IsClicked(Point p) const;
		virtual bool IsConnected() const;
};
