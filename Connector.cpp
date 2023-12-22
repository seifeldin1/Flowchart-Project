#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;
}
bool Connector:: IsPointClicked(Point P) const {
	return true; /// ana 7atet implementation ay 7aga 3alshan yebata yedy errors laken me7taga tet8ayar tab3an
}
void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Save(ofstream& Output)
{
	//Saves the connector in format Src:id1 ,Dst:id2 ,Drawing points: (x1,y1),(x2,y2)
	Output << "Src:" << SrcStat->GetID() << " ,"
		   << "Dst:" << DstStat->GetID() << " ,"
		   << "Drawing points: " << '(' << Start.x << ',' << Start.y << ')' << ','
		   << '(' << End.x << ',' << End.y << ')' << endl;
	//ADD OUTLET BRANCH AFTER CONDITIONAL IS DONE
}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector(Start, End);
}

