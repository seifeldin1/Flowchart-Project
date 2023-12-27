#ifndef STATEMENT_H
#define STATEMENT_H

//#include "..\GUI\UI_Info.h"
//class Output;
#include "..\GUI\Output.h"
#include "..\Connector.h"
#include "..\ApplicationManager.h"

//Base class for all Statements
class Statement
{
	//Point position;
protected:

	int ID;				//Each Statement has an ID --> must be unique
	static int NextID;

	Point LeftCorner;
	string Text;		//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;		//true if the statement is selected on the flowchart
	Connector* StandardConn;
	StatementType Type;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	

	//Statement(Point currentPosition);



	
	//string ReturnVariable();

	//int GetWidth(); //return width of statment

	//int GetHeight(); //return height of statment
	
	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Edit() = 0;		//Edit the Statement parameter

	///TODO: Add more functions if needed

	//============================ Class functions ============================
	Statement(Point Lcorner, string text);
	Statement(ifstream& input);

	void Move(Point Lcorner);							//moves the statement to point
	void SetSelected(bool s);							//sets if statement is selected or not
	bool IsSelected() const;							//returns true if statement is selected
	int GetID();										//returns ID of each unique statement
	string GetText();									//returns text inside the statement
	Point GetLcorner() const;							//returns top left corner point of statement
	StatementType GetType();
	//these 2 are virtual because of condition statement
	virtual Connector* GetOutConnector(int=0) const;			//returns a connector coming out of statement
	virtual void SetOutConnector(Connector* outcon);	//sets a connector coming out of statement

	~Statement();
	//============================ Pure Virtual functions ============================
	virtual void Draw(Output* pOut) const = 0;			//Draws the statement
	virtual bool IsPointClicked(Point P) const = 0;		//returns true if statement has been clicked on
	virtual void Simulate(ApplicationManager* pManager) = 0;						//Execute the statement in the simulation mode
	virtual void Save(ofstream& OutFile) = 0;			//Save the Statement parameters to a file
	virtual void Load(ifstream& Infile) = 0;			//Load the Statement parameters from a file
	virtual Statement* Copy() = 0;						//copy statement and return a pointer of type statement	
	//virtual void GenerateCode(ofstream& OutFile) = 0;	//generates code

};

#endif