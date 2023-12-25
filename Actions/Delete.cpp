#include"Delete.h"
Delete::Delete(ApplicationManager* pManager):Action(pManager){}

void Delete::ReadActionParameters() {
	return;
}

void Delete::Execute() {
	delConn = pManager->GetSelectedConnector();
	delStat = pManager->GetSelectedStatement();
	if (delConn) {// if delete connector pointer doesn't = NULL
		pManager->RemoveConnFromList(delConn);
		
		pManager->SetSelectedConnector(NULL);
		return;
	}
	if (delStat) {
		pManager->RemoveStatFromList(delStat);

	}

}
