#include "Write.h"
///khalas ba2a katbtaha keteer te3ebt bas bardo other functions ma3ana tetktb
Statement* Write::Copy() {
	copyWrite = new Write(Point(0, 0), ((Write*)this)->variable);
	return copyWrite;
}
