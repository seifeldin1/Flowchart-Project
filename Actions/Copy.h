#pragma once
#include "Action.h"

class Copy :public Action
{

public:

	Copy(ApplicationManager* pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();

};