#include "Statement.h"

class WriteState : public Statement
{
	private:
		string Variable;

		Connector* pInConn[200];     //Write Stat. has one connector coming to it
		Connector* pOutConn;	     //Write Stat. has one Connector to next statement

		int WriteInConnCount;

		Point Inlet;	//A point where connections enters this statement 
					    //It's used as the (End) point of the (Input) connectors
		Point Outlet;	//A point a connection leaves this statement
					    //It's used as the (Start) point of the (Output) connector

		Point LeftCorner;	//top left corner of the statement block

		virtual void UpdateStatementText();

	public:
		WriteState(Point Lcorner, string var = "");
		void SetVariable(string var);
		Point GetLcorner() const;
		Point GetInlet() const;
		Point GetOutlet() const;
		int ReturnStatType();
		void Draw(Output* pOut) const;
		bool IsPointClicked(Point P) const;
		void SetInConnector(Connector* incon);
		void SetOutConnector(Connector* outcon);
		Connector* GetInConnector() const;
		Connector* GetOutConnector() const;
		int GetConnInCount() const;

};