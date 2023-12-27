#pragma once
#include "Action.h"
#include"..\Statements\ReadState.h"
class AddRead :
    public Action
{
    string variable;
    Point P; //point where user clicks
public:
    AddRead(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

