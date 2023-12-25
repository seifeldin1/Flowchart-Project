#pragma once
#include"Action.h"
#include "..\Statements\Conditional.h"
class Paste:public Action
{
	Statement* paste;
	Point P;
public:
	Paste(ApplicationManager* pManager);
	void ReadActionParameters();
	void SetDrawingPoint(Point P);
	void Execute();
};

