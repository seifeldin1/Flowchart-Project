#pragma once
#include "Action.h"


class Delete :public Action
{
	private:
		Point Position;

	public:
		Delete(ApplicationManager* pManager);
		void ReadActionParameters();
		void Execute();
};
