#pragma once
#include "Statement.h"
class VariableAssign :
    public Statement
{
    Point lc;
    Statement* copyVariable;
    string LHS, RHS;
    virtual void UpdateStatementText();
public:
    VariableAssign(Point LeftCorner, string LeftHandSide, string RightHandSide);
    Statement* Copy();
};

