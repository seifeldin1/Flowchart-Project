#include "Statement.h"
//#include "..\GUI\UI_Info.h"

Statement::Statement(int outConn, bool canTakeInConnector)
{ 
	//TODO: set the ID with a unique value
	Text = "";
	Selected = false;		
}
//Statement::Statement(Point currentPosition) : position(currentPosition){}

//int Statement::GetWidth() { return ASSGN_WDTH; }
//int Statement::GetHeight() { return ASSGN_HI; }

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID()
{
	return ID;
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