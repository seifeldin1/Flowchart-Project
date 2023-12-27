#pragma once
#include"Action.h"
#include "..\Statements\ConditionalState.h"
#include "..\Statements\EndStat.h"
#include "..\Statements\Start.h"
#include "..\Statements\AssignStat.h"
#include "..\Statements\ReadState.h"
#include "..\Statements\WriteState.h"


class Paste :public Action
{
	Statement* paste;
	Point P;
public:
	Paste(ApplicationManager* pManager);
	void ReadActionParameters();
	void SetDrawingPoint(Point P);
	void Execute();
};

