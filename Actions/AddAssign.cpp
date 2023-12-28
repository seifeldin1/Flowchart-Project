#include "AddAssign.h"


#include "..\Statements\AssignStat.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddAssign::AddAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	RLHS = '0';
	Operator = '0';
	RRHS = '0';
	Point P;
	//Read the (Position) parameter
	pOut->PrintMessage("Click to add the  assigment statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
	//Getting type of assignment statement user wants
	
	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter 1:Value , 2:Variable or 3:Operator Assignment");
	pIn->GetPointClicked(P);
	Type = pIn->GetValue(pOut);
	pOut->PrintMessage("Enter LHS: ");
	LHS = pIn->GetVariable(pOut);
	//TODO: Ask the user in the status bar to enter the RHS and set the data member
	if (Type == 1) //Value Assingment Statement
	{
		pOut->PrintMessage("Enter RHS: ");
		string rhs = pIn->GetString(pOut);
		while (IsValue(rhs) != true)
		{
			pOut->PrintMessage("Invalid, Re-enter a double: ");
			string rhs = pIn->GetString(pOut);
		}
		RHS = rhs;
	}
	else if (Type == 2) //Variable Assingment Statement
	{
		pOut->PrintMessage("Enter RHS: ");
		RHS = pIn->GetVariable(pOut);
	}
	else if (Type == 3) //Operator Assingment
	{
		pOut->PrintMessage("Enter operator:");
		string Op = pIn->GetArithOperator(pOut);
		pOut->PrintMessage("Enter LHS of operator:");
		string s1 = pIn->GetString(pOut);
		pOut->PrintMessage("Enter RHS of operator:");
		string s2 = pIn->GetString(pOut);
		RLHS = s1;
		Operator = Op;
		RRHS = s2;
		RHS = s1 + Op + s2;
	}
}

void AddAssign::Execute()
{
	ReadActionParameters();

	//TODO: should set the LHS and RHS of pAssign statement
	AssignStat* pAssign = new AssignStat(Position, LHS, RHS , RLHS, Operator, RRHS);

	//with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}

