#include "Statement.h"

class ConditionalState : public Statement
{
	private:
		string LHS; //Left Handside of the assignment (name of a variable)
		string Comp_Operator;
		string RHS; //Right hand side (variable or double)

		int CondInConnCount; //count of connectors going into statement
		int CondOutConnCount;
		Connector* pInConn[200];
		Connector *pOutConn[2];

		Point Inlet; //A point where connections enters this statement 

		Point Outlet;//A point a connection leaves this statement

		Point LeftCorner;

		virtual void UpdateStatementText();

		Statement* copyConditional;
	public:
		ConditionalState(Point Lcorner, string LeftHS = "", string RightHS = "", string comparisonOP = "");

		Statement* Copy();

		void setLHS(const string &L);
		void setRHS(const string &R);
		void setCompOp(const string& comOp);

		Point GetLcorner() const;
		int ReturnStatType();
		void Draw(Output* pOut) const;
		bool IsPointClicked(Point P) const;
		void SetInConnector(Connector* incon);
		void SetOutConnector(Connector* outcon);
		Connector* GetInConnector() const;
		Connector* GetOutConnector() const;
		int GetConnInCount() const;

		string GetOperator();

		//implementing this function to avoid value assign statement being an abstract class
		int GetOutConnCount() const;

		~ConditionalState();
};