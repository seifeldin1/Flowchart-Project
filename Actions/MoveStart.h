#pragma once
#include "Action.h"
class MoveStart : public Action
{
private:
	Point Lcorner;
public:
	MoveStart(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};

