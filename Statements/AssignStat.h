#ifndef VALUE_ASSIGN_H
#define VALUE_ASSIGN_H

#include "Statement.h"

//Value Assignment statement class
//The value assignment statement assigns a value to a variable
class AssignStat : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)
	Statement* copyValue;
	//Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	int ValueAssInConnCount; //count of connectors going into statement
	
	Connector* pInConn[200];
	Connector *pOutConn;	//Value Assignment Stat. has one Connector to next statement
	                        //Each statement type in flowchart has a predefined number of (output) connectors
	                        //For example, conditional statement always has 2 output connectors

	                        //Note: We don't need to keep track with input connectors
	                        //      Whenever we want to iterate on all statements of the flowchart
	                        //      we will begin with start statement then its output connector
	                        //      then the connector's destination statement and so on (follow the connectors)

	Point Inlet;	//A point where connections enters this statement 
	                //It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	                //It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//top left corner of the statement block

	virtual void UpdateStatementText();
	
public:
	AssignStat(Point Lcorner, string LeftHS="", double RightHS=0);
	
	void setLHS(const string &L);
	void setRHS(double R);
	Statement* Copy();
	virtual void Draw(Output* pOut) const;
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
	~AssignStat();
};

#endif