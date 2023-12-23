#ifndef STATEMENT_H
#define STATEMENT_H

//#include "..\GUI\UI_Info.h"
//class Output;
#include "..\GUI\Output.h"
#include "..\Connector.h"


//Base class for all Statements
class Statement
{
	//Point position;
protected:
	int ID;			//Each Statement has an ID --> must be unique
	static int NumberOfStatements; //number of statements drawn on screen
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the flowchart
	Output* pOut; // Pointer to Output


	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement(Output * pOut);
	//Statement(Point currentPosition);


	//int GetWidth(); //return width of statment

	//int GetHeight(); //return height of statment
	
	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file

	friend class Connector;
	///TODO: Add more functions if needed
	void SetSelected(bool s);
	bool IsSelected() const;
	int GetID();
	string GetText();
	virtual Point GetInlet()const;
	virtual Point GetOutlet() const;

	virtual int ReturnStatType() = 0; //returns type of statement
	virtual void Draw(Output* pOut) const = 0;	//Draw the statement
	virtual bool IsPointClicked(Point P) const = 0; //returns true if statement has been clicked on
	virtual bool IsConnected() const = 0; // returns true if statement is connected
	virtual void SetConnector(Connector* con) = 0; //sets a connector for statement
	~Statement();
};

#endif