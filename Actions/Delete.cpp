#include "Delete.h"
Delete::Delete(ApplicationManager* pAppManager) :Action(pAppManager) {}

void Delete::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select a statement or connector to be deleted");
}

void Delete::Execute() {
	ReadActionParameters();
	Statement* delStat = pManager->GetSelectedStatement();
	Connector* delConn = pManager->GetSelectedConnector();
	if (!delStat && !delConn) {
		Output* pOut;
		pOut->PrintMessage("No selected connectors or statements to delete");
	}

	else if (delConn) pManager->RemoveConnectorFromList(delConn);

	else if (delStat) {
		pManager->RemoveStatementFromList(delStat);
		pManager->DeleteConnectedConnectors(delStat);
	}
}