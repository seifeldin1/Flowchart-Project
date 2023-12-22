#ifndef Save_H
#define Save_H

#include "Action.h"

class Save :
    public Action
{
private:
    string Filename;    //Name for the file in which user will store the data
public:
    Save(ApplicationManager* pAppManager);
    void ReadActionParameters();
    void Execute();
};

#endif