#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h"
#include "..\HelperFn.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   //Class forward declaration
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Input(window* pW);		//Consturctor
	void GetPointClicked(Point& P) const;//Gets coordinate where user clicks

	
	double GetValue(Output* pO) const;	// Reads a double value from the user 

	string GetString(Output* pO) const; //Returns a string entered by the user


	// to read a �variable name� from the user (from the keyboard). 
	// It does not return before taking a valid variable name.
	string GetVariable(Output* pO);

	
	// to read an arithmetic operator (+, -, * or /) from the user. 
	// It does not return before taking a valid arithmetic operator.
	string GetArithOperator(Output* pO);

	
	// similar to the previous function but for comparison operators (==, !=, <, <=, > or >=).
	string GetCompOperator(Output* pO);


	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	~Input();
};

#endif