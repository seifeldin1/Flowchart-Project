#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst,int B)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	SrcStat = Src;
	DstStat = Dst;
	Branch = B;
}
bool Connector:: IsPointClicked(Point P) const 
{
	if ( ((P.x >= Start.x - 5 && P.x <= Start.x + 5) && (P.x >= End.x - 5 && P.x <= End.x + 5)) && (P.y >= Start.y && P.y <= End.y) )
		return true;
	else
		return false;
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
	Output << SrcStat->GetID() << " " <<  DstStat->GetID() << " " << Branch << endl;
}
void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector(Start, End);
}

