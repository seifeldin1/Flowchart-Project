#include "Statement.h"

class ConditionalState : public Statement
{
private:
	string LHS; //Left Handside of the assignment (name of a variable)
	string Operator;
	string RHS; //Right hand side (variable or double)

	Connector* Yconn;
	Connector* Nconn;
	Connector* ResultConn;
	
	virtual void UpdateStatementText();

public:

	//============================ Class functions ============================
	ConditionalState(Point Lcorner, string LeftHS, string RightHS, string comparisonOP);
	ConditionalState(ifstream& input);

	void setLHS(string L);
	void setRHS(string R);
	void setOp(string comOp);
	//string GetOperator();

	virtual Connector* GetOutConnector(int branch);			//returns a connector coming out of statement
	virtual void SetOutConnector(Connector* outcon, int branch);	//sets a connector coming out of statement

	~ConditionalState();
	//============================ Pure Virtual functions implementation ============================
	virtual void Draw(Output* pOut) const;			//Draws the statement
	virtual bool IsPointClicked(Point P) const;		//returns true if statement has been clicked on
	virtual void Simulate();						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
	virtual Statement* Copy();						//copy statement and return a pointer of type statement	
	virtual void GenerateCode(ofstream& OutFile);	//generates code
};