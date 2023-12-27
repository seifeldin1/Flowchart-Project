#include "SwitchTSM.h"
SwitchTSM::SwitchTSM(ApplicationManager* pAppManager) :Action(pAppManager) {}

void SwitchTSM::ReadActionParameters() {
	Output* pOut;
	pOut->PrintMessage("Switching to simulation mode...");
}

void SwitchTSM::Execute() {
	if (UI.AppMode == DESIGN) {
		ReadActionParameters();
		Output* pOut;
		pOut->CreateSimulationToolBar();
		pOut->ClearStatusBar();
	}
}
