#pragma once
#include "Action.h"
class Exit :
    public Action
{
public:
	Exit(ApplicationManager* pManager);

	void ReadActionParameters();
	void Execute();
};

