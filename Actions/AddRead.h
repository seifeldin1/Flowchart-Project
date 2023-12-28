#pragma once
#include "Action.h"
class AddRead :
    public Action
{
    string variable;
    Point Point,P; //point where user clicks
public:
    AddRead(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

