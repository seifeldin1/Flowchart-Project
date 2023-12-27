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
	int ID;		//Each Statement has an ID --> must be unique
	static int NumberOfStatements; //number of statements drawn on screen
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the flowchart
	bool CanConnect; //check if it can get a In connector (Start is false , other is true)
	int MaxOutConnectors; //return max number of out connectors (0 for end , 2 for conditional , others is 1)
	Point Leftcorner;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement(int outConn , bool canTakeInConnector); 

	//Statement(Point currentPosition);



	
	string ReturnVariable();
	virtual Statement* Copy() = 0;//copy statement and return a pointer of type statement	
	//int GetWidth(); //return width of statment

	//int GetHeight(); //return height of statment
	
	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	//virtual void Edit() = 0;		//Edit the Statement parameter

	virtual void Simulate();	//Execute the statement in the simulation mode

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file

	///TODO: Add more functions if needed

	void Move(Point Lcorner);


	void SetSelected(bool s);//sets if statement is selected or not
	bool IsSelected() const; //returns true if statement is selected
	int GetID(); //returns ID of each unique statement
	string GetText();
	virtual Point GetInlet()const; //returns Inlet point of statement
	virtual Point GetOutlet() const; //returns outlet point of statement
	virtual Point GetLcorner() const = 0; //returns top left corner point of statement
	string ReturnVariable();

	virtual int ReturnStatType() = 0; //returns type of statement
	virtual void Draw(Output* pOut) const = 0;	//Draw the statement
	virtual bool IsPointClicked(Point P) const = 0; //returns true if statement has been clicked on
	virtual void SetInConnector(Connector* incon) = 0; //sets a connector going to statement
	virtual void SetOutConnector(Connector* outcon) = 0; //sets a connector coming out of statement
	virtual Connector* GetInConnector() const = 0; //returns a connector going to statement
	virtual Connector* GetOutConnector() const = 0; //returns a connector coming out of statement
	virtual int GetConnInCount() const = 0; //returns count of connectors going to statement
	virtual int GetConnOutCount() const = 0; //returns count of connectors coming out of statement
	~Statement();
};

#endif