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

	Point LeftCorner;	//top left corner of the statement block

	virtual void UpdateStatementText();
	
public:
	AssignStat(Point Lcorner, string LeftHS="", double RightHS=0);
	
	void setLHS(string L);
	void setRHS(string R);
	Point GetLcorner() const;
	int ReturnStatType();
	void Draw(Output* pOut) const;
	bool IsPointClicked(Point P) const;
	void SetOutConnector(Connector* outcon);
	Connector* GetOutConnector() const;
	~AssignStat();
};


enum Assigntype
{
	Variable,
	Value,
	Operator,
};

#endif