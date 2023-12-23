#include "Copy.h"
template<typename T>
Copy<T>::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{}

template<typename T>
void Copy<T>::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select Statment to copy");
	original=pManager->GetSelectedStatement();
	
}

template<typename T>
void Copy<T>::Execute() {
	if (original == NULL)return;
	pManager->AddStatement(original);
	copy = original;
	pManager->SetClipboard(copy);


}
