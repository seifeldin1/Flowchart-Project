#include "Action.h"
#include "..\\Connector.h"

class Select : public Action
{
	private:
		Point Position;
	public:
		Select(ApplicationManager* pAppManager);

		//Read Assignemt statements position
		virtual void ReadActionParameters();

		//Create and add an assignemnt statement to the list of statements
		virtual void Execute();
};