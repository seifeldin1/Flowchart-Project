#include "VariableAssign.h"
///.....
Statement* VariableAssign::Copy() {
	copyVariable = new VariableAssign(Point(0, 0), ((VariableAssign*)this)->LHS, ((VariableAssign*)this)->RHS);
	return copyVariable;
}
