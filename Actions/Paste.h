#pragma once
#include"Action.h"



class Paste :public Action
{
	Point P;
public:
	Paste(ApplicationManager* pManager);
	void ReadActionParameters();
	void SetDrawingPoint(Point P);
	void Execute();
};

