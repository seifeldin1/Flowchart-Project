#pragma once
#include "Action.h"

class Valid : public Action
{
private:
	bool Validate_Status;
public:
	Valid(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
	bool IsValidated();
};

