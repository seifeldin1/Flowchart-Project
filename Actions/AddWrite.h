#include "Action.h"
#include"..\Statements\WriteState.h"
class AddWrite : public Action
{
private:
	Point P;
	string variable;
public:
	AddWrite(ApplicationManager* pManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};