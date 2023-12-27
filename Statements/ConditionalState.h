#include "Statement.h"

class ConditionalState : public Statement
{
private:
	string LHS; //Left Handside of the assignment (name of a variable)
	string Comp_Operator;
	string RHS; //Right hand side (variable or double)

	Connector *pOutConn[2];

	virtual void UpdateStatementText();

public:

	//============================ Class functions ============================
	ConditionalState(Point Lcorner, string LeftHS = "", string RightHS = "", string comparisonOP = "");

	void setLHS(const string& L);
	void setRHS(const string& R);
	void setCompOp(const string& comOp);

	string GetOperator();

	~ConditionalState();
	//============================ Pure Virtual functions implementation ============================
	virtual void Draw(Output* pOut) const;			//Draws the statement
	virtual bool IsPointClicked(Point P) const;		//returns true if statement has been clicked on
	virtual void Simulate();						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
	virtual Statement* Copy();						//copy statement and return a pointer of type statement	
};