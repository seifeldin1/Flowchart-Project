#pragma once
#include "Action.h"

class Validate : public Action
{
private:
	Output* pOut;
	bool Validate_Status;
public:
	void ReadActionParameters();
	void Execute();
	bool IsValidated();
};

