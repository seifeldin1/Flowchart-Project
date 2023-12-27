#pragma once
#include "Action.h"
class AddStart :
    public Action
{
    Point P; //point where user clicks
public:
    AddStart(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

