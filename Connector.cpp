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

void Connector::CalcStartnEnd()
{
	Point SrcP = SrcStat->GetLcorner();
	Point DstP = DstStat->GetLcorner();
	int Ydiff = DstP.y - SrcP.y;
	int Xdiff = DstP.x - SrcP.x;
	if (Ydiff > 0)
	{
		if (Xdiff > 40)
		{
			Start = SrcP;
		}
		else if(Xdiff < -40)
		{

		}
	}
	else if (Ydiff > 0)
	{

	}
	else if (Ydiff == 0)
}

void Connector::Draw(Output* pOut)
{
	CalcStartnEnd();
	pOut->DrawConnector(Start, End);
}

