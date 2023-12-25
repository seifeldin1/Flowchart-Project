#pragma once
#include "Statement.h"
class Conditional :
    public Statement
{
    string LHS, Comp_operator, RHS; // Left handside and right handside could be either variable or value (for example 4<x , x>4 , y>x) 
                                   // comparison operator needed because in conditiobal we can get (x+4)                
    Statement* copyConditional; 
    Point lc; //points to left corner of block
    virtual void UpdateStatementText();

public:
    Conditional(Point LeftCorner , string LeftHandSide="", string RightHandSide="", string comparisonOP=""); // in implementing constructor 7awel tesheel el ="" w tesebhom string bas 
                                                                                                                //w gowa le constructor tekhaleeha =""
    Statement* Copy();
};

