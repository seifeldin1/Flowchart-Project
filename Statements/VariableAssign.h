#include "Statement.h"

class VariableAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (Value)
	int VarAssInConnCount; //count of connectors going into statement

	Connector* pInConn[200];
	Connector* pOutConn;	//Value Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 

	Point Outlet;	//A point a connection leaves this statement


	Point LeftCorner;	//top left corner of the statement block

	virtual void UpdateStatementText();

public:
	VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string &L);
	void setRHS(const string &R);
	Point GetLcorner() const;
	int ReturnStatType();
	void Draw(Output* pOut) const;
	bool IsPointClicked(Point P) const;
	void SetInConnector(Connector* incon);
	void SetOutConnector(Connector* outcon);
	Connector* GetInConnector() const;
	Connector* GetOutConnector() const;
	int GetConnInCount() const;

	//implementing this function to avoid value assign statement being an abstract class
	int GetOutConnCount() const;

	~VariableAssign();
};