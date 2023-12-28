#include "Action.h"
class AddWrite : public Action
{
private:
	Point Point;
	string variable;
public:
	AddWrite(ApplicationManager* pManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};