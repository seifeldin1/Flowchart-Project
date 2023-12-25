#pragma once
#include "Action.h"
class Delete : public Action {
	Statement* delStat;
	Connector* delConn;
public:
	Delete(ApplicationManager* pManager);

	virtual void ReadActionParameters();

	virtual void Execute();

};