#pragma once
#include "Statement.h"
class End :
    public Statement
{
    Point lc;//points to left corner of block
    Statement* copyEnd;
    void UpdateStatementText();
public:
    End(Point leftCorner);
    Statement* Copy();
};

