#pragma once
#include "Action.h"
class SwitchTSM :
    public Action
{

public:

	SwitchTSM(ApplicationManager* pManager);

	void ReadActionParameters();
	void Execute();
};

