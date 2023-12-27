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

Connector* Statement::GetOutConnector() const
{
	return StandardConn;
}

void Statement::SetOutConnector(Connector* outcon)
{
	StandardConn = outcon;
}

/*
string Statement::ReturnVariable()
{
	string Name = Text;

	size_t pos = Name.find_first_of("=<> ");

	if (pos != string::npos)
	{
		Name = Name.substr(0, pos);
	}

	return Name;
}
*/

Statement::~Statement()
{
}