#include "Read.h"
///constructor , update....
Statement* Read::Copy() {
	copyRead = new Read(Point(0, 0), ((Read*)this)->variable);
	return copyRead;
}