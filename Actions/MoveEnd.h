#pragma once
#include "Action.h"
class MoveEnd : public Action
{
private:
	Point Lcorner;
public:
	MoveEnd(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
};

