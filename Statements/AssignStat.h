#ifndef VALUE_ASSIGN_H
#define VALUE_ASSIGN_H

#include "Statement.h"

enum Assigntype;
//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class AssignStat : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside

	Assigntype type;		//differentiates between assignemnt types

	Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	virtual void UpdateStatementText();
	
public:

	//============================ Class functions ============================
	AssignStat(Point Lcorner, string LeftHS, string RightHS);
	AssignStat(ifstream& input);

	void setLHS(string L);							//Sets the left hand side
	void setRHS(string R);							//Sets the right hand side

	~AssignStat();

	//============================ Pure Virtual functions implementation ============================
	virtual void Draw(Output* pOut) const;			//Draws the statement
	virtual bool IsPointClicked(Point P) const;		//returns true if statement has been clicked on
	virtual void Simulate() {};						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
	virtual Statement* Copy();						//copy statement and return a pointer of type statement	
};


enum Assigntype
{
	Variable,
	Value,
	Operator,
};

#endif