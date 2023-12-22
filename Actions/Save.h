#ifndef Save_H
#define Save_H

#include "Actions/Action.h"

class Save :
    public Action
{
private:
    string Filename;
public:
    Save(ApplicationManager* pAppManager);
    void ReadActionParameters();
    void Execute();
};

#endif