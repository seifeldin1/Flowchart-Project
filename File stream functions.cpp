#include "Connector.h"

ofstream& operator <<(ofstream& Output, Connector* Conn)
{
	Conn->Save(Output);
}