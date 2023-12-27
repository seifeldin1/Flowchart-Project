#pragma once
#include "Action.h"
#include "Valid.h"
class Debug :
    public Action
{
public:
    Debug(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

