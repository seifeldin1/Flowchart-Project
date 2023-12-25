#include "Conditional.h"
Statement* Conditional::Copy() {
	copyConditional = new Conditional(Point(0,0) , ((Conditional*)this)->LHS , ((Conditional*)this)->RHS , ((Conditional*)this)->Comp_operator);
	return copyConditional;
}