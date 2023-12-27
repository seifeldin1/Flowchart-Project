#include"AddCond.h"
AddCond::AddCond(ApplicationManager*):Action(pManager){}

void AddCond::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click where you want to add");
	pIn->GetPointClicked(P);
	pOut->PrintMessage("Enter left hand side");
	LHS = pIn->GetVariable(pOut);
	pOut->PrintMessage("Enter comparison operator");
	CompOP = pIn->GetCompOperator(pOut);
	pOut->PrintMessage("Is your right hand side a value or variable? (val for value and var for variable)");
	valORvar = pIn->GetString(pOut);
	while (valORvar != "val" && valORvar != "var") {
		pOut->PrintMessage("Error! enter val for value and var for variable");
		valORvar = pIn->GetString(pOut);
	}
	if (valORvar == "val") {
		pOut->PrintMessage("Enter right hand side");
		RHS = pIn->GetValue(pOut);
	}
	else {
		pOut->PrintMessage("Enter right hand side");
		RHS = pIn->GetVariable(pOut);
	}
	

}

void AddCond::Execute() {
	ReadActionParameters();

	ConditionalState* pCond = new ConditionalState(P, LHS, RHS, CompOP);

	pManager->AddStatement(pCond);
}
