#include "Statement.h"

class OperatorAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;
	string RHS1;	//Right Handside 1
	string RHS2;	//Right Handside 2
	string ArthOp;
					// LHS "=" RHS1 Arhtimetric Operator RHS2

	int OpAssInConnCount; //count of connectors going into statement
	Connector* pInConn[200];
	Connector* pOutConn;	 //Value Assignment Stat. has one Connector to next statement
	

	Point Inlet;	//A point where connections enters this statement 
	
	Point Outlet;	//A point a connection leaves this statement
	

	Point LeftCorner;	//top left corner of the statement block

	virtual void UpdateStatementText();

public:
	OperatorAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string &L);
	void setRHS(const string &R);
	void setRHS1(const string& R1);
	void setRHS2(const string& R2);
	void setArthOp(const string &arthOp);
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
	~OperatorAssign();
};