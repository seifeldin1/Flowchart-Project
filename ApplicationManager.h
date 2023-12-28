#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "Statements\Statement.h"
#include "Connector.h"

class Input;
class Output;


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCount = 200 };	//Max no of statements/connectors in a single flowchart

private:
	int StatCount;		//Actual number of statements
	int ConnCount;		//Actual number of connectors
	Statement* StatList[MaxCount];	//List of all statements (Array of pointers)
	Connector* ConnList[MaxCount];	//List of all connectors (Array of pointers)

	Statement *pSelectedStat; //a pointer to the last selected statement
	                          //you can set and get this pointer
	Statement *pClipboard;    //a pointer to the last copied/cut statement
	                          //you can set and get this pointer
	Connector* pSelectedConn;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	int IntVariableCount;
	string* IntVariables;
	double IntVariablesValue[200];

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// == Actions Related Functions ==
	ActionType GetUserAction() const;	//Reads the input command from the user 
										//and returns the corresponding action type
	void ExecuteAction(ActionType) ;	//Creates an action and executes it
	void SaveAll(ofstream& Output);		//saves all statements and connectors
	void LoadAll(ifstream& Input);
	void MoveSt(Point Lcorner);
	void MoveEn(Point Lcorner);
	
	// == Statements/Connector Management Functions ==
	void AddStatement(Statement* pStat);    //Adds a new Statement to the Flowchart
	Statement *GetStatement(Point P) const;	//Searches for a statement where point P belongs
	Statement *GetStatement(int ID) const; //TODO: Complete its implementation 
	                                        //      WITHOUT breaking class responsibilities

	void AddConnector(Connector* pConn);    //Adds a new Connector to the Flowchart
	Connector *GetConnector(Point P) const;	//search for a Connector where point P belongs

	// Note: you should use the following 4 functions 
	//       in order not to break class responsibilities (especially in copy, cut and paste)
	Statement *GetSelectedStatement() const;	 //Returns the selected Statement
	void SetSelectedStatement(Statement *pStat); //Set the Statement selected by the user
	Statement *GetClipboard() const;	         //Returns the Clipboard
	void SetClipboard(Statement *pStat);         //Set the Clipboard
	void SetSelectedConnector(Connector* pConn); //Set the Connector selected by the user
	Connector* GetSelectedConnector() const;	//Return the connector selected
	void RemoveConnectorFromList(Connector* pConn); //Remove connector from connector list
	void RemoveStatementFromList(Statement* pStat); //Remove statement from statement list
	void DeleteConnectedConnectors(Statement* pStat); //Delete all connected connectors to a statement id a statement is deleted
	int GetConnCount();
	int GetStatCount();
	// == Interface Management Functions ==
	Input *GetInput() const;        //Return pointer to the input
	Output *GetOutput() const;      //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window


	//Bonus functions
	void Debug();






	// Seif Funcs
	bool CheckNumConn();
	bool CheckVariableInit();
	bool CheckConnections();
	void RunFlow();
	double ReturnValue(string x);
	int GetIntVariableCount();
	string* GetIntVariable();
	void AddIntVariable(string x, double a);

};

#endif