#pragma once
#include "Action.h"
class AddConn : public Action
{
private:
	Statement* Src;
	Statement* Dst;
	int branch;
public:

	AddConn(ApplicationManager* pAppManager);
	virtual void ReadActionParameters() ;
	virtual void Execute();
};

