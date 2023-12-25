#pragma once
#include "Statement.h"

class StartState : public Statement
{
	private:
		Point Outlet;      //A point where connections leaves this statement
		                   //It's used as the (Start) point of the (Output) connector
		Point LeftCorner;  //top left corner of the statement block
		
		Connector* pOutConn; //Start Stat. has one Connector to next statement

		virtual void UpdateStatementText();

	public:
		StartState(Point Lcorner);

		Point GetLcorner() const;
		Point GetOutlet() const;
		int ReturnStatType();
		void Draw(Output *pOut) const;
		bool IsPointClicked(Point P) const;
		void SetOutConnector(Connector* outcon);
		Connector* GetOutConnector() const;

		~StartState();
};