#include "Copy.h"
Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{}


void Copy::ReadActionParameters() {
	return;
	
}


void Copy::Execute() {
	original = pManager->GetSelectedStatement();
	if (original == NULL) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No statement selected to be copied!");
	}
	else {
		copy = original->Copy();
		clipboard = pManager->GetClipboard();
		if (clipboard != NULL) {
			delete clipboard;
		}
		pManager->SetClipboard(copy);
		pManager->SetSelectedStatement(NULL);
		original->SetSelected(false);
	}
	pManager->AddStatement(original);
	copy = original;
	pManager->SetClipboard(copy);


}
