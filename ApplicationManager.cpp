#include "ApplicationManager.h"
#include "Actions/AddAssign.h"
#include "Actions/Save.h"
#include "Actions/Copy.h"
#include "Actions/Load.h"
#include "Actions/MoveStart.h"
#include "Actions/MoveEnd.h"
#include "Statements/StartStat.h"
#include "Statements/EndStat.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 2;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;


	//Creates static Start and ends
	Point Pstart(0, UI.ToolBarHeight+3);
	StatList[0] = new StartStat(Pstart);
	Point Pend(UI.DrawingAreaWidth - UI.ASSGN_WDTH - 3, UI.height - UI.StatusBarHeight);
	StatList[1] = new EndStat(Pend);

	//Create an array of Statement pointers and set them to NULL		
	for(int i=2; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
	case MOVE_START:
		pAct = new MoveStart(this);
		break;

	case MOVE_END:
		pAct = new MoveEnd(this);
		break;

	case ADD_ASSIGN:
		pAct = new AddAssign(this);
		break;

	case ADD_CONDITION:
		///create AddCondition Action here

		break;

	case SELECT:
		///create Select Action here

		break;

	case EXIT:
		///create Exit Action here
		
		break;

	case SAVE:
		pAct = new Save(this);
		break;

	default:
		return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}

void ApplicationManager::SaveAll(ofstream& Output)
{
	Output << StatCount << endl;
	for (int i = 0; i < StatCount; i++)
	{
		//StatList[i]->Save(Output);
	}

	Output << endl << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++)
	{
		ConnList[i]->Save(Output);
	}
}

void ApplicationManager::LoadAll(ifstream& input)
{
	string type="";
	Statement* pStat;
	input >> StatCount;
	for (int i = 0; i < StatCount; i++)
	{
		input >> type;
		if (type == "AssignStat")
			pStat = new AssignStat(input);
		else if (type == "CondStat")
			pStat
	}
}

void ApplicationManager::MoveSt(Point Lcorner)
{
	StatList[0]->Move(Lcorner);
}

void ApplicationManager::MoveEn(Point Lcorner)
{
	StatList[1]->Move(Lcorner);
}


//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	if (StatList[0] == NULL) return NULL; //checks if statment list is not empty
	for (int i = 0; i < StatCount; i++) {
		if (StatList[i]->IsPointClicked(P)) {
			return StatList[i];
		}
	}


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}

//= ================================================================================ =//
//						Connector Management Functions								 //
//==================================================================================//

void ApplicationManager::AddConnector(Connector* pConn) { //Adds a connector
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}

Connector* ApplicationManager::GetConnector(Point P) const
{
	//If this point P(x,y) belongs to a coonector return a pointer to it.
	//otherwise, return NULL
	if (ConnList[0] == NULL) return NULL; //checks if statment list is not empty
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i]->IsPointClicked(P)) {
			return ConnList[i];
		}
		//remaining: check that P is inside the list otherwise return null
	}


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////// Seif Functions //////////////////////////////////////////////////////////////////////

/*
	0 -- > Start
	1 -- > End
	2 -- > Assign Value
	3 -- > Read Parallelogram
	4 -- > Write Parallelogram 
	5 -- > Rhombus
*/

/*

bool ApplicationManager::CheckStartEnd()
{
	int StartCount = 0, EndCount = 0;
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->ReturnStatType() == 0)
		{
			StartCount++;
		}
		if (StatList[i]->ReturnStatType() == 1)
		{
			EndCount++;
		}
	}
	if (StartCount != 1 || EndCount != 1)
		return false;
	else
		return true;
}

bool ApplicationManager::CheckConnections()
{
	for (int i = 0; i < ConnCount; i++)
	{
		//Check for nodes that are not reachable
		if (ConnList[i]->getSrcStat() == NULL && ConnList[i]->getSrcStat()->ReturnStatType() != 0) // not Start and doesnt Have Source
			return false;

		else if (ConnList[i]->getDstStat() == NULL && ConnList[i]->getDstStat()->ReturnStatType() != 1) // not End and doesnt Have Destination 
			return false;
		
		else if (ConnList[i]->getDstStat() == NULL && ConnList[i]->getSrcStat() == NULL) // a flying node in air
			return false;

		// Check that if there is a Cycle 
		else if (ConnList[i]->getDstStat() == ConnList[i]->getSrcStat())
			return false;
	}
	return true;
}


bool ApplicationManager::CheckVariableInit()
{
	int VarCount = 0;

	// Count The Number Of Variables

	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->ReturnStatType() == 2 || StatList[i]->ReturnStatType() == 3)
		{
			VarCount++;
		}
	}

	int *VarIndex = new int [VarCount];
	string *VarText = new string[VarCount];
	int ArrayCount = 0;

	// Store Variables In Array

	for (int j = 0; j < StatCount; j++)
	{
		if (StatList[j]->ReturnStatType() == 2 || StatList[j]->ReturnStatType() == 3)
		{
			VarIndex[ArrayCount] = j;
			VarText[ArrayCount] = StatList[j]->ReturnVariable();
			ArrayCount++;
		}
	}

	// check if the Variable is Initialized before being Used

	for (int k = 0; k < StatCount; k++)
	{
		for (int l = 0; l < ArrayCount; l++)
		{
			if (StatList[k]->ReturnVariable() == VarText[l] && k < VarIndex[l])
			{
				delete []VarIndex;
				delete []VarText;
				return false;
			}
		}
	}

	delete []VarIndex;
	delete []VarText;
	return true;
}

bool ApplicationManager::CheckNumConn()
{
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[j]->ReturnStatType() == 5 && StatList[j]->GetConnOutCount() != 2)
			return false;
	}
	return true;
}

void ApplicationManager::RunFlow()
{
	Statement* pStat;

	//Search For the Start Statement
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->ReturnStatType() == 0)
		{
			pStat = StatList[i];
			break;
		}
	}

	while (pStat->GetOutConnector() != NULL)
	{
		pStat->Simulate();
		pStat = pStat->GetOutConnector()->getDstStat();
	}
}
*/
///////////////////////////////////////////////////////// End of Seif Functions //////////////////////////////////////////////////////////////////////



//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}

