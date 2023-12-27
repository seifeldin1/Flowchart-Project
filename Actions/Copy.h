#pragma once
#include "Action.h"

class Copy :public Action
{

	Statement* copy;
	Statement* original = NULL;
	Statement* clipboard;

public:

	Copy(ApplicationManager* pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();

};

#pragma once
#include "Action.h"

class Copy :public Action
{

	Statement* copy;
	Statement* original = NULL;
	Statement* clipboard;

public:

	Copy(ApplicationManager* pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();

};

