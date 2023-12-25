#pragma once
#include "Validate.h"

class Run : public Action
{
private:
	Validate* validate_Act;
	Output* pOut;
public:
	Run(ApplicationManager* pAppManager, Validate* validate_Act);
	void ReadActionParameters();
	void Execute();
};

