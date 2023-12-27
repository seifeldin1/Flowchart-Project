#pragma once
#include "Action.h"
#include "Validate.h"
class Debug :
    public Action
{
public:
    Debug(ApplicationManager* pManager);

    void ReadActionParameters();
    void Execute();
};

