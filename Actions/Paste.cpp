#include"Paste.h"

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click anywhere to Paste the Statement");
	pIn->GetPointClicked(P);

}
void Paste:: SetDrawingPoint(Point P) {
	if (dynamic_cast<Conditional*> (pManager->GetClipboard()));
			// to be continued.
}
void Paste::Execute() {
	if (pManager->GetClipboard() == NULL) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Statement in clipboard to paste ");
	}
	else {
		ReadActionParameters();
		paste = (pManager->GetClipboard())->Copy();
		//paste->SetDrawingPoint(P);
		pManager->AddStatement(paste);
		//idk yet if i should draw here or not
	}
}