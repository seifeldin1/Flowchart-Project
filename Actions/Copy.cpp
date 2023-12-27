#include "Copy.h"
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{}


void Copy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select a statement to be copied!");

}


void Copy::Execute() {
	Statement* original = pManager->GetSelectedStatement();
	if (original == NULL) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No statement selected to be copied!");
	}
	else {
		/*copy = original->Copy();
		clipboard = pManager->GetClipboard();
		if (clipboard) {
			delete clipboard;
		}*/
		pManager->SetClipboard(original->Copy());
		pManager->SetSelectedStatement(NULL);
		original->SetSelected(false);
	}

}
