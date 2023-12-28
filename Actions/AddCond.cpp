#include"AddCond.h"
#include "..\Statements\ConditionalState.h"
AddCond::AddCond(ApplicationManager* pAppManager) : Action (pAppManager){}

void AddCond::ReadActionParameters() 
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Click where you want to add");
	pIn->GetPointClicked(Point);
	pOut->PrintMessage("Enter left hand side");
	LHS = pIn->GetVariable(pOut);
	pOut->PrintMessage("Enter comparison operator");
	CompOP = pIn->GetCompOperator(pOut);
	pOut->PrintMessage("Is your right hand side a value or variable? (val for value and var for variable)");
	valORvar = pIn->GetString(pOut);
	while (valORvar != "val" && valORvar != "var") {
		pOut->PrintMessage("Error! enter 'val' for value and 'var' for variable");
		valORvar = pIn->GetString(pOut);
	}
	if (valORvar == "val") 
	{
		pOut->PrintMessage("Enter right hand side (val)");
		string rhs = pIn->GetString(pOut);
		while (IsValue(rhs) != true)
		{
			pOut->PrintMessage("Invalid, Re-enter a double: ");
			rhs = pIn->GetString(pOut);
		}
		RHS = rhs;
	}
	else 
	{
		pOut->PrintMessage("Enter right hand side (var)");
		string rhs = pIn->GetString(pOut);
		while (IsVariable(rhs) != true)
		{
			pOut->PrintMessage("Invalid, Re-enter variable: ");
			rhs = pIn->GetString(pOut);
		}
		RHS = rhs;
	}
}

void AddCond::Execute() 
{
	ReadActionParameters();

	ConditionalState* pCond = new ConditionalState(Point, LHS, RHS, CompOP);

	pManager->AddStatement(pCond);
}
