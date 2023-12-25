#include "Start.h"
#include<sstream>


void Start::UpdateStatementText() {
	ostringstream T;
	T << "Start";
	Text = T.str(); //stores string in text
}
Start::Start(Point LeftCorner):Statement(1,false) {
	UpdateStatementText();
	lc = LeftCorner; //now the private data member lc is pointing to the left corner position of my object



};

Statement* Start::Copy(){
	 copyStart = new Start(Point(0, 0)); // will work when other fuctions implemented ///stores a copy of start in copy
	 return copyStart;

}
