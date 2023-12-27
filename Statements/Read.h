#pragma once
#include"Statement.h"
class Read:public Statement
{
	Statement* copyRead;
	Point lc;
	string variable;
	virtual void UpdateStatementText();
public:
	Read(Point LeftCorner, string var = "");
	Statement* Copy();
	Point getLeftCorner();
};

