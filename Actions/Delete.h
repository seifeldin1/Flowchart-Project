#pragma once
#include "Action.h"


class Delete :public Action
{

public:

	Delete(ApplicationManager* pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();


};
