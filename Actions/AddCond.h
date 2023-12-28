#pragma once
#include "Action.h"

class AddCond :public Action {
	Point Point;
	string LHS , RHS , CompOP , valORvar;
public:
	AddCond(ApplicationManager* pManager);
	void ReadActionParameters();
	void Execute();
};