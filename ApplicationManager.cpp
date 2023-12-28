#include "ApplicationManager.h"
#include "Actions/AddAssign.h"
#include "Actions/Save.h"
#include "Actions/Copy.h"
#include "Actions/Load.h"
#include "Actions/MoveStart.h"
#include "Actions/MoveEnd.h"
#include "Statements/StartStat.h"
#include "Statements/EndStat.h"
#include "Statements/ConditionalState.h"
#include "Statements/ReadState.h"
#include "Statements/WriteState.h"
#include"Statements/AssignStat.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"Actions/AddCond.h"
#include"Actions/AddConn.h"
#include"Actions/AddRead.h"
#include"Actions/AddWrite.h"
#include"Actions/AddAssign.h"
#include"Actions/Debug.h"
#include"Actions/Delete.h"
#include"Actions/Exit.h"
#include"Actions/Paste.h"
#include"Actions/SwitchTSM.h"
#include"Actions/Select.h"

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
	Point Pstart(0, UI.ToolBarHeight+5);
	StatList[0] = new StartStat(Pstart);
	Point Pend(UI.DrawingAreaWidth - UI.ASSGN_WDTH - 5, UI.height - UI.StatusBarHeight -UI.ASSGN_HI);
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
		pAct = new AddCond(this);
		break;

	case SELECT:
		///create Select Action here
		pAct = new Select(this);
		break;

	case EXIT:
		///create Exit Action here
		pAct = new Exit(this);
		break;

	case SAVE:
		pAct = new Save(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case COPY:
		pAct = new Copy(this);
		break;

	case PASTE:
		pAct = new Paste(this);
		break;

	case ADD_CONNECTOR:
		pAct = new AddConn(this);
		break;

	case ADD_READ:
		pAct = new AddRead(this);
		break;

	case ADD_WRITE:
		pAct = new AddWrite(this);
		break;

	case DEL:
		pAct = new Delete(this);
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
		StatList[i]->Save(Output);
	}

	Output << endl << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++)
	{
		ConnList[i]->Save(Output);
	}
}

void ApplicationManager::LoadAll(ifstream& input)
{
	for (int i = 0; i < StatCount; i++)
	{
		StatList[i] = NULL;
	}

	for (int i = 0; i < ConnCount; i++)
	{
		StatList[i] = NULL;
	}
	pOut->ClearDrawArea();
	StatCount = 0; ConnCount = 0;
	string type="";
	Statement* pStat;
	int StatementCount, ConnectorCount;
	input >> StatementCount;
	for (int i = 0; i < StatementCount; i++)
	{
		pStat = NULL;
		input >> type;
		if (type == "AssignStat")
			pStat = new AssignStat(input);
		else if (type == "CondStat")
			pStat = new ConditionalState(input);
		else if (type == "Start")
			pStat = new StartStat(input);
		else if (type == "End")
			pStat = new EndStat(input);
		else if (type == "Read")
			pStat = new ReadState(input);
		else if (type == "Write")
			pStat = new WriteState(input);
		AddStatement(pStat);
	}

	int ID1, ID2, branch;
	Statement *Src, *Dst;
	input >> ConnectorCount;
	Connector* pConn;
	for (int i = 0; i < StatCount; i++)
	{
		pConn = NULL;
		input >> ID1 >> ID2 >> branch;
		Src = GetStatement(ID1);
		Dst = GetStatement(ID2);
		pConn = new Connector(Src,Dst,branch);
		AddConnector(pConn);
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
	if (pStat == NULL) return;
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

Statement* ApplicationManager::GetStatement(int ID) const
{
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->GetID() == ID)
			return StatList[i];
	}
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

void ApplicationManager :: RemoveStatementFromList(Statement* pStat) {
	int i;
	if (pStat == StatList[0] || pStat == StatList[1])
	{
		pOut->PrintMessage("Can not delete start or end");
		return;
	}
	for (i = 0; i < StatCount && StatList[i] != pStat; i++); // to know the index of needed statement to be removed
	if (i < StatCount) {
		int k = i;
		for (i < k; i < StatCount; i++) StatList[i] = StatList[i + 1]; //to keep it ordered
		StatList[StatCount - 1] = NULL;
		StatCount--;
	}
}

//====================================================================================//
//						Connector Management Functions								 //
//==================================================================================//

void ApplicationManager::AddConnector(Connector* pConn) { //Adds a connector
	if (pConn == NULL) return;
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
void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedConn = pConn;
}
Connector* ApplicationManager::GetSelectedConnector() const {
	return pSelectedConn;
}
void ApplicationManager::RemoveConnectorFromList(Connector* pConn) {
	int i;
	for (i = 0; i < ConnCount && ConnList[i] != pConn; i++); // to know the index of needed connector to be removed
	if (i < ConnCount) {
		int k = i;
		for (i < k; i < ConnCount; i++) ConnList[i] = ConnList[i + 1]; //to keep it ordered
		ConnList[ConnCount - 1] = NULL;
		ConnCount--;
	}
}

void ApplicationManager:: DeleteConnectedConnectors(Statement* pStat) {
	int i;
	for (i = 0; i < ConnCount; i++) { // to know the index of needed connectors to be deleted
		if (ConnList[i]->getDstStat() == pStat || ConnList[i]->getSrcStat() == pStat) {
			int k = i;
			for (i < k; i < ConnCount; i++) ConnList[i] = ConnList[i + 1]; //to keep it ordered
			ConnList[ConnCount - 1] = NULL;
			ConnCount--;
		}
	}
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

	pOut->ClearStatusBar();
	pOut->ClearOutputBar();
	if (UI.AppMode == DESIGN)
		pOut->CreateDesignToolBar();
	else
		pOut->CreateSimulationToolBar();
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


bool ApplicationManager::CheckConnections()
{
	Statement* pStat = StatList[0];

	while (pStat->GetOutConnector() != NULL)
	{
		pStat = pStat->GetOutConnector()->getDstStat();
	}
	return true;
}


bool ApplicationManager::CheckNumConn()
{
	for (int i = 0; i < StatCount; i++)
	{
		if (dynamic_cast<ConditionalState*>(StatList[i]) != NULL && (StatList[i]->GetOutConnector(1) == NULL || StatList[i]->GetOutConnector(2) == NULL))
			return false;
	}
	return true;
}

void ApplicationManager::RunFlow()
{
	Statement* pStat = StatList[0];

	while (pStat->GetOutConnector() != NULL)
	{
		pStat->Simulate();
		pStat = pStat->GetOutConnector()->getDstStat();
	}
}
///////////////////////////////////////////////////////// End of Seif Functions //////////////////////////////////////////////////////////////////////

void ApplicationManager::AddIntVariable(string x, double a)
{
	bool notfound = true;
	if (IntVariableCount < MaxCount)
	{
		for (int i = 0; i < IntVariableCount; i++)
		{
			if (IntVariables[i] == x)
				notfound = false;
		}
	}
	if (notfound == true)
	{
		IntVariables[IntVariableCount] = x;
		IntVariablesValue[IntVariableCount] = a;
		IntVariableCount++;
	}
	if (notfound == false)
	{
		for (int i = 0; i < IntVariableCount; i++)
		{
			if (IntVariables[i] == x)
				IntVariablesValue[i] = a;
		}
	}
}
string* ApplicationManager::GetIntVariable()
{
	return IntVariables;
}



int ApplicationManager::GetIntVariableCount()
{
	return IntVariableCount;
}

double ApplicationManager::ReturnValue(string x)
{
	for (int i = 0; i < IntVariableCount; i++)
	{
		if (IntVariables[i] == x)
		{
			return IntVariablesValue[i];
		}
	}
	return 0.0;
}


/////////////////////////////////////////"DEBUGGING"//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Debug() {
	Statement* pStat;
	Output* pOut;
	Input* pIn;
	string c;
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->GetType() == START)
		{
			pStat = StatList[i];
			SetSelectedStatement(pStat);
			pOut->PrintMessage("Step by step run has started. Enter (stop) to stop");
			c = pIn->GetString(pOut);
			if (c == "stop")break;
			UpdateInterface();
			break;
		}

	}
	if (c == "stop")return;
	while (pStat->GetType() != END)
	{
		// pStat->
	}
}







//Destructor
ApplicationManager::~ApplicationManager()
{
	/*
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	*/
}

