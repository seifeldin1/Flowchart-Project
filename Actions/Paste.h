#pragma once
#include"Action.h"
#include "..\Statements\ConditionalState.h"
#include "..\Statements\EndStat.h"
#include "..\Statements\StartStat.h"
#include "..\Statements\AssignStat.h"
#include "..\Statements\ReadState.h"
#include "..\Statements\WriteState.h"


class Paste :public Action
{
	Point P;
public:
	Paste(ApplicationManager* pManager);
	void ReadActionParameters();
	void SetDrawingPoint(Point P);
	void Execute();
};

