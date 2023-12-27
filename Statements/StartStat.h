#pragma once
#include "Statement.h"

class StartStat : public Statement
{
private:

	virtual void UpdateStatementText() {};

	Statement* copyStart;
public:


	//============================ Class functions ============================
	StartStat(Point Lcorner);
	StartStat(ifstream& input);



	~StartStat();
	//============================ Pure Virtual functions ============================
	virtual void Draw(Output* pOut) const;						//Draws the statement
	virtual bool IsPointClicked(Point P) const;					//returns true if statement has been clicked on
	 virtual void Simulate(ApplicationManager* pManager);	//Execute the statement in the simulation mode
	 virtual void Save(ofstream& OutFile);					//Save the Statement parameters to a file
	 virtual void Load(ifstream& Infile);					//Load the Statement parameters from a file
	 virtual Statement* Copy();								//copy statement and return a pointer of type statement
};