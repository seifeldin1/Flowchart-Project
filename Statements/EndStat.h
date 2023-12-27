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


	void Draw(Output* pOut) const;
	bool IsPointClicked(Point P) const;

	~EndStat();

	//============================ Pure Virtual functions implementation ============================
	virtual void Simulate();				//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile);	//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile);	//Load the Statement parameters from a file
	virtual Statement* Copy();				//copy statement and return a pointer of type statement	
};
