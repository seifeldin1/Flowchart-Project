#pragma once
#include "Action.h"

class Copy :public Action
{

public:

	Copy(ApplicationManager* pManager);

	void ReadActionParameters();
	void Execute();

};