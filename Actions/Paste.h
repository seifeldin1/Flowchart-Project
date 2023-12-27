#pragma once
#include"Action.h"
#include "..\Statements\Conditional.h"
#include "..\Statements\EndStat.h"
#include "..\Statements\Start.h"
#include "..\Statements\OperatorAssign.h"
#include "..\Statements\Read.h"
#include "..\Statements\VariableAssign.h"
#include "..\Statements\Write.h"
#include "..\Statements\ValueAssign.h"



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

