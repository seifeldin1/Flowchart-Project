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
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the flowchart


	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	//Statement(Point currentPosition);
	void SetSelected(bool s);
	bool IsSelected() const;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	virtual bool IsPointClicked(Point P) const = 0; //each statement class gets its own implementation

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


	///TODO: Add more functions if needed
	virtual Point GetInPoint() const;
	virtual Point GetOutPoint() const;
	virtual bool IsClicked(Point P) const = 0;
	virtual bool IsConnected() const = 0;


};

#endif