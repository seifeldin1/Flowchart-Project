#include "Statement.h"

class ReadState : public Statement
{
	private:
		string Variable;

		Connector* pInConn[200];     //Write Stat. has one connector coming to it
		Connector* pOutConn;	     //Write Stat. has one Connector to next statement

		int ReadInConnCount;

		Point Inlet;	//A point where connections enters this statement 

		Point Outlet;	//A point a connection leaves this statement


		Point LeftCorner;	//top left corner of the statement block

		virtual void UpdateStatementText();
	public:
		ReadState(Point Lcorner, string var = "");
		void SetVariable(string var);
		Point GetLcorner() const;
		int ReturnStatType();
		void Draw(Output* pOut) const;
		bool IsPointClicked(Point P) const;
		void SetInConnector(Connector* incon);
		void SetOutConnector(Connector* outcon);
		Connector* GetInConnector() const;
		Connector* GetOutConnector() const;
		int GetConnInCount() const;

		//implementing this function to avoid write statement being an abstract class
		int GetConnOutCount() const;
		~ReadState();

};