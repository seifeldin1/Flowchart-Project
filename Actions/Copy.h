#pragma once
#include "Action.h"
template<typename T>
class Copy :public Action
{
	
	T copy;
	T *original==NULL;
	ApplicationManager* pManager;
public:
	
	Copy(ApplicationManager*pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();
};

