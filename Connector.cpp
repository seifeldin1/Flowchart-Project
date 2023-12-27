#include "Connector.h"
#include "Statements/ConditionalState.h"

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
	bool IsCondStat1 = false, IsCondStat2 = false;
	if (dynamic_cast<ConditionalState*>(SrcStat) != NULL) IsCondStat1 = true;
	if (dynamic_cast<ConditionalState*>(DstStat) != NULL) IsCondStat1 = true;
	int Ydiff = DstP.y - SrcP.y;
	int Xdiff = DstP.x - SrcP.x;
	if (Ydiff > 40 || (Xdiff<40 && Xdiff>40 && Ydiff>0))
	{
		Start.x = SrcP.x += ((IsCondStat1) ? (UI.COND_WDTH / 2) : (UI.ASSGN_WDTH / 2));
		Start.y = SrcP.y += ((IsCondStat1) ? (UI.COND_HI) : (UI.ASSGN_HI));
		End.x = DstP.x += ((IsCondStat2) ? (UI.COND_WDTH / 2) : (UI.ASSGN_WDTH / 2));
		End.y = DstP.y;
	}
	else if (Ydiff < -40 || (Xdiff < 40 && Xdiff>40 && Ydiff < 0))
	{
		Start.x = SrcP.x += ((IsCondStat1) ? (UI.COND_WDTH / 2) : (UI.ASSGN_WDTH / 2));
		Start.y = SrcP.y;
		End.x = DstP.x += ((IsCondStat2) ? (UI.COND_WDTH / 2) : (UI.ASSGN_WDTH / 2));
		End.y = DstP.y += ((IsCondStat2) ? (UI.COND_HI) : (UI.ASSGN_HI));
	}
	else
	{
		if (Xdiff > 40)
		{
			Start.x = SrcP.x += ((IsCondStat1) ? (UI.COND_WDTH) : (UI.ASSGN_WDTH));
			Start.y = SrcP.y += ((IsCondStat1) ? (UI.COND_HI / 2) : (UI.ASSGN_HI / 2));
			End.x = DstP.x;
			End.y = DstP.y += ((IsCondStat2) ? (UI.COND_HI / 2) : (UI.ASSGN_HI / 2));
		}
		else if (Xdiff < -40)
		{
			Start.x = SrcP.x;
			Start.y = SrcP.y += ((IsCondStat1) ? (UI.COND_HI / 2) : (UI.ASSGN_HI / 2));
			End.x = DstP.x += ((IsCondStat2) ? (UI.COND_WDTH) : (UI.ASSGN_WDTH));
			End.y = DstP.y += ((IsCondStat2) ? (UI.COND_HI / 2) : (UI.ASSGN_HI / 2));
		}
	}
}

void Connector::Draw(Output* pOut)
{
	CalcStartnEnd();
	pOut->DrawConnector(Start, End);
}

