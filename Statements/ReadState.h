#include "Statement.h"

class ReadState : public Statement
{
private:
	string Variable;
	Connector* pOutConn;	     //Write Stat. has one Connector to next statement
	double Value;
	int ReadInConnCount;

	virtual void UpdateStatementText();

public:
	//============================ Class functions ============================
	ReadState(Point Lcorner, string var = "");
	void SetVariable(string var);

	~ReadState();
	//============================ Pure Virtual functions implementation ============================
	virtual void Draw(Output* pOut) const;			//Draws the statement
	virtual bool IsPointClicked(Point P) const;		//returns true if statement has been clicked on
	virtual void Simulate();						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
	virtual Statement* Copy();						//copy statement and return a pointer of type statement	

};