#include "Statement.h"
//#include "..\GUI\UI_Info.h"

int Statement::NextID = 0;

Statement::Statement(Point Lcorner,string text="")
{
	LeftCorner = Lcorner;
	ID = NextID++;
	Text = text;
	Selected = false;	
	StandardConn = NULL;
}
Statement::Statement(ifstream& input)
{
	Load(input);
	Selected = false;
	StandardConn = NULL;
}
void Statement::Move(Point Lcorner)
{
	LeftCorner = Lcorner;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID()
{
	return ID;
}

string Statement::GetText()
{
	return Text;
}

Point Statement::GetLcorner() const
{
	return LeftCorner;
}

Connector* Statement::GetOutConnector(int) const
{
	return StandardConn;
}

void Statement::SetOutConnector(Connector* outcon)
{
		StandardConn = outcon;
}
StatementType Statement::GetType() {
	return Type;
}

void Statement::Load(ifstream& Infile)
{

}

Statement::~Statement()
{
}

