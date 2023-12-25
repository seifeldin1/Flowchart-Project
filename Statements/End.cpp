#include "End.h"
/// do update statement text such as I did in start w zay ma heya implemented fel assign value
Statement* End::Copy() {
	copyEnd = new End(Point(0, 0)); // makes a copy of End
	return copyEnd;
}
