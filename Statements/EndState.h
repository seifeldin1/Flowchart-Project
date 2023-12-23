#pragma once
#include "Statement.h"

class EndState:public Statement
{
	private:
		Point Inlet;       //A point where connections enters this statement 
		Point LeftCorner;  //top left corner of the statement block.
		
		Connector *pInConn; //End Stat. has one Connector from previous statement

		virtual void UpdateStatementText();

	public:
		EndState(Point Lcorner);

		virtual int ReturnStatType();
		virtual void Draw(Output *pOut) const;
		virtual bool IsPointClicked(Point P) const;
		virtual bool IsConnected() const;
		virtual void SetConnector(Connector* con);

		~EndState();
};
