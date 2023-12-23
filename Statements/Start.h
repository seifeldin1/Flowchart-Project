#pragma once
#include "Statement.h"
class Start :
    public Statement
{
    Point lc;
    Statement* copyStart;
    virtual void UpdateStatementText();
public:
    Start(Point leftCorner);
    Statement* Copy();
};

