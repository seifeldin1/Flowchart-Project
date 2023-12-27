#include "Exit.h"
Exit::Exit(ApplicationManager* pAppManager) :Action(pAppManager) {}


void Exit::ReadActionParameters() { return; }

void Exit::Execute() { delete pManager; }
