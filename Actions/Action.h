#ifndef ACTION_H
#define ACTION_H

//#include "CMUgraphicsLib\CMUgraphics.h"

#include "..\GUI\UI_Info.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//Base class for all possible actions
class Action
{
protected:
	
	//Pointer to ApplicationManager because action needs this pointer for its functions
	ApplicationManager *pManager;	

public:

	Action(ApplicationManager *pAppManager) 
	{ pManager = pAppManager; }
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;
};

#endif