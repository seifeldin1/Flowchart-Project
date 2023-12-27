#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
#include "Statements/Statement.h"

class Connector	//a connector that connects two statements (Source & Destination)
{

private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point End;		//End point of the connector
	int Branch;

public:
	Connector(Statement* Src, Statement* Dst, int B=0);
	virtual bool IsPointClicked(Point P) const; //to be implemented in connector class

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	void Save(ofstream &Output);

	void Draw(Output* pOut) const;
};

#endif