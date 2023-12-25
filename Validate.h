#pragma once
#include "Actions/Action.h"
#include "GUI/Output.h"
#include "Statements/Statement.h"
#include "Connector.h"

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

