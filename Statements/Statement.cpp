#include "Statement.h"
//#include "..\GUI\UI_Info.h"

Statement::Statement(int outConn, bool canTakeInConnector)
{ 
	//TODO: set the ID with a unique value
	NumberOfStatements++;
	ID = NumberOfStatements;
	Text = "";
	Selected = false;		
}
//Statement::Statement(Point currentPosition) : position(currentPosition){}

//int Statement::GetWidth() { return ASSGN_WDTH; }
//int Statement::GetHeight() { return ASSGN_HI; }

void Statement::Move(Point Lcorner)
{
	Leftcorner = Lcorner;
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
Point Statement::GetInlet() const
{
	return NULL;
}
Point Statement::GetOutlet() const
{
	return NULL;
}

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

Statement::~Statement()
{
	NumberOfStatements--;
}

