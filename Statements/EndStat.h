#pragma once
#include "Statement.h"

class EndStat : public Statement
{
private:

	virtual void UpdateStatementText();

	Statement* copyEnd;
public:


	//============================ Class functions ============================
	EndStat(Point Lcorner);
	EndStat(ifstream& input);


	
	~EndStat();
	//============================ Pure Virtual functions implementation ============================
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointClicked(Point P) const;
	virtual void Simulate();	//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);					//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);					//Load the Statement parameters from a file
	virtual Statement* Copy();								//copy statement and return a pointer of type statement	
};
