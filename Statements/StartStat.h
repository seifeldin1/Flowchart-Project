#pragma once
#include "Statement.h"

class StartStat : public Statement
{
private:
	Point LeftCorner;  //top left corner of the statement block
	
	Connector* pOutConn; //Start Stat. has one Connector to next statement

	virtual void UpdateStatementText() {};

public:
	//============================ Class functions ============================
	StartStat(Point Lcorner);

	~StartStat();

	virtual void Draw(Output* pOut) const;			//Draws the statement
	virtual bool IsPointClicked(Point P) const;		//returns true if statement has been clicked on

	//============================ Pure Virtual functions ============================

	virtual void Simulate();						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
	virtual Statement* Copy();						//copy statement and return a pointer of type statement	
};