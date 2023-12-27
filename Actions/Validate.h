#pragma once
#include "Action.h"
#include "../GUI/Output.h"
#include "../Statements/Statement.h"
#include "../Connector.h"

class Validate : public Action
{
private:
	bool Validate_Status;
public:
	Validate(ApplicationManager* pAppManager);
	void ReadActionParameters();
	void Execute();
	bool IsValidated();
};

