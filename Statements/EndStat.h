#pragma once
#include "Statement.h"

class EndStat : public Statement
{
private:

	virtual void UpdateStatementText();

	Statement* copyEnd;
public:
	EndStat(Point Lcorner);

	Statement* Copy();
	
	void Draw(Output *pOut) const;
	bool IsPointClicked(Point P) const;
	
	

	~EndStat();
};
