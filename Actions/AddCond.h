#pragma once
#include "Action.h"
#include "..\Statements\ConditionalState.h"
class AddCond :public Action {
	Point P;
	string LHS , RHS , CompOP , valORvar;
public:
	AddCond(ApplicationManager* pManager);
	void ReadActionParameters();
	void Execute();
};