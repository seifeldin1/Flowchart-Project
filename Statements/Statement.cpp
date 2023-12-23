#include "Statement.h"
//#include "..\GUI\UI_Info.h"

Statement::Statement()	
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
Point Statement::GetInPoint() const
{
	return NULL;
}

Point Statement::GetOutPoint() const
{
	return NULL;
}

