#pragma once
#include "Action.h"
class AddEnd :
    public Action
{
    Point P; //point where user clicks
public:
    AddEnd(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

