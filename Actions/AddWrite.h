#include "Action.h"

class AddWrite : public Action
{
private:
	Point Position;
	string Variable;
public:
	AddWrite(ApplicationManager* pManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};