#pragma once
#include "Statement.h"

class EndStat : public Statement
{
private:

	Point LeftCorner;  //top left corner of the statement block

	virtual void UpdateStatementText();

	Statement* copyEnd;
public:
	EndStat(Point Lcorner);

	Statement* Copy();
	Point GetLcorner() const;
	void Draw(Output *pOut) const;
	bool IsPointClicked(Point P) const;
	void SetInConnector(Connector* incon);

	~EndStat();
};
