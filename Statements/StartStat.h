#pragma once
#include "Statement.h"

class StartStat : public Statement
{
private:

	virtual void UpdateStatementText() {};

public:

	//============================ Class functions ============================
	StartStat(Point Lcorner);
	StartStat(ifstream& input);

	~StartStat();
	//============================ Pure Virtual functions ============================
	 void Draw(Output* pOut);			//Draws the statement
	 bool IsPointClicked(Point P);		//returns true if statement has been clicked on
	 void Simulate(ApplicationManager* pManager);						//Execute the statement in the simulation mode
	 void Save(ofstream& OutFile);			//Save the Statement parameters to a file
	 void Load(ifstream& Infile);			//Load the Statement parameters from a file
	 Statement* Copy();						//copy statement and return a pointer of type statement	
};