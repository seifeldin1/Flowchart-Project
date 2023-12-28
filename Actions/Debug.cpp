#include "Debug.h"
Debug:: Debug(ApplicationManager* pManager) :Action(pManager){}

void Debug::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Debugging step by step...");
}

void Debug::Execute() {
	
	/*
	Valid* valid;
	if (valid->IsValidated()) {
		ReadActionParameters();
		
	}
	else {
		Output* pOut;
		pOut->PrintMessage("your flowchart is not valid");
	}
	*/
}