#include "Statement.h"
//#include "..\GUI\UI_Info.h"

Statement::Statement(Output*pout)	
{ 
	//TODO: set the ID with a unique value
	NumberOfStatements++;
	ID = NumberOfStatements;
	Text = "";
	pOut = pout;
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
Statement::~Statement()
{
	NumberOfStatements--;
	pOut = NULL;
}

