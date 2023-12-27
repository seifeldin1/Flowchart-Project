#pragma once
#include "Action.h"
class Undo :
    public Action
{
    Point P;
public:
    Undo(ApplicationManager* pManager);


    void ReadActionParameters();
    virtual void Execute();
};

