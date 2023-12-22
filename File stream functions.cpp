#include "Connector.h"
#include "Statements/Statement.h"

ofstream& operator <<(ofstream& Output, Connector *Conn)
{
	Conn->Save(Output);
	return Output;
}

ofstream& operator <<(ofstream& Output, Statement *Stat)
{
	//Stat->save();
	return Output;
}