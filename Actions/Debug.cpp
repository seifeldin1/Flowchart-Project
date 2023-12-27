#include "Debug.h"
Debug:: Debug(ApplicationManager* pManager) :Action(pManager){}

void Debug::ReadActionParameters() {
	Output* pOut;
	pOut->PrintMessage("Debugging step by step...");
}

void Debug::Execute() {
	ReadActionParameters();
	Validate* valid;
	if (valid->IsValidated()) {
		ReadActionParameters();
		for(int i =0 ; i< pManager.)
	}
}