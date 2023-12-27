#include"Paste.h"

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to Paste the Statement");
}
void Paste::SetDrawingPoint(Point P) {
	if (dynamic_cast<ConditionalState*> (pManager->GetClipboard())) P = (pManager->GetClipboard())->GetLcorner(); //function to draw 

	else if (dynamic_cast<ReadState*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->GetLcorner();

	else if (dynamic_cast<WriteState*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->GetLcorner();

	else if (dynamic_cast<AssignStat*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->GetLcorner();

	else if (dynamic_cast<EndStat*>(pManager->GetClipboard())) {
		Output* pOut;
		pOut->PrintMessage("only one end is allowed to be in project");

	}
	else if (dynamic_cast<Start*>(pManager->GetClipboard())) {
		Output* pOut;
		pOut->PrintMessage("only one end is allowed to be in project");
	}


}
void Paste::Execute() {
	if (pManager->GetClipboard() == NULL) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No Statement in clipboard to paste ");
	}
	else {
		ReadActionParameters();
		Input* pIn = pManager->GetInput();
		pIn->GetPointClicked(P);
		Statement* paste = (pManager->GetClipboard())->Copy();
		SetDrawingPoint(P);
		pManager->AddStatement(paste);
	}
}