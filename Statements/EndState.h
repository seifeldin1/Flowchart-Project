#pragma once
#include "Statement.h"

class EndState:public Statement
{
	private:
		Point Inlet;       //A point where connections enters this statement 
		                   //It's used as the (End) point of the (Input) connectors
		Point LeftCorner;  //top left corner of the statement block
		int EndInConnCount; //count of connector going to end statement
		Connector* pInConn[200]; //array of all connectors going to end statement

		virtual void UpdateStatementText();

		Statement* copyEnd;
	public:
		EndState(Point Lcorner);
		
		Statement* Copy();

		Point GetLcorner() const;
		int ReturnStatType();
		void Draw(Output *pOut) const;
		bool IsPointClicked(Point P) const;
		void SetInConnector(Connector* incon);
		Connector* GetInConnector() const;
		int GetConnInCount() const;

		//implementing these functions to avoid end statement being an abstract class
		void SetOutConnector(Connector* outcon);
		Connector* GetOutConnector() const;
		int GetConnOutCount() const;
		~EndState();
};
