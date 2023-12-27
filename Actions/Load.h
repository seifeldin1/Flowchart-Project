#pragma once
#include "Action.h"
class Load : public Action
{
private:
    string Filename;    //Name for the file in which user will store the data
public:
    Load(ApplicationManager* pAppManager);
    void ReadActionParameters();
    void Execute();
};

