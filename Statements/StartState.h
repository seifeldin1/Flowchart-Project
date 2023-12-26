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

		Statement* copyStart;
	public:
		StartState(Point Lcorner);

		Statement* Copy();

		Point GetLcorner() const;
		int ReturnStatType();
		void Draw(Output *pOut) const;
		bool IsPointClicked(Point P) const;
		void SetOutConnector(Connector* outcon);
		Connector* GetOutConnector() const;

		//implementing these functions to avoid start statement being an abstract class
		void SetInConnector(Connector* incon);
		Connector* GetInConnector() const;
		int GetConnInCount() const;
		int GetConnOutCount() const;

		~StartState();
};