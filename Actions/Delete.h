#pragma once
#include "Action.h"
#include "..\Statements\StartStat.h"
#include "..\Statements\ReadState.h"
#include "..\Statements\EndStat.h"
#include "..\Statements\ConditionalState.h"
#include "..\Statements\AssignStat.h"
#include "..\Statements\WriteState.h"

class Delete :public Action
{

public:

	Delete(ApplicationManager* pManager);
	//Copy(const Copy& c) : clipboard(c.clipboard);

	void ReadActionParameters();
	void Execute();


};
