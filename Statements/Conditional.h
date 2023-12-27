#pragma once
#include "Statement.h"
class Conditional : public Statement
{
    string LHS, Comp_operator, RHS;               
    Statement* copyConditional; 
    Point lc; //points to left corner of block
    virtual void UpdateStatementText();

public:
    Conditional(Point LeftCorner , string LeftHandSide="", string RightHandSide="", string comparisonOP=""); 
    Statement* Copy();
};

