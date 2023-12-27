#include"Paste.h"

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to Paste the Statement");
}
void Paste:: SetDrawingPoint(Point P) {
	if (dynamic_cast<Conditional*> (pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner(); //function to draw 

	else if (dynamic_cast<Read*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<Write*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<OperatorAssign*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<VariableAssign*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<ValueAssign*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<End*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

	else if (dynamic_cast<Start*>(pManager->GetClipboard())) P = (pManager->GetClipboard())->getLeftCorner();

			
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
		paste = (pManager->GetClipboard())->Copy();
		SetDrawingPoint(P);
		pManager->AddStatement(paste);
	}
}