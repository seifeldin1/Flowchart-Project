#pragma once
#include "Statement.h"
class Write :
    public Statement
{
	Statement* copyWrite;
	Point lc;
	string variable;
	virtual void UpdateStatementText();
public:
	Write(Point LeftCorner, string var = "");
	Statement* Copy();
};

