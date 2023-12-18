
#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
	return Label;
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D

	double D = 0;
		
	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.).
	string UserDouble;
	pO->PrintMessage("Enter a value:");
	
	//Read a double value from the user
	while (1) //while loop used to make sure user will enter a valid double to be used
	{
		UserDouble = GetString(pO); //Gets string through pointer that points to user double entered
		if (IsValue(UserDouble) == true)
		{
			D = stod(UserDouble); break;
		}
		else
		{
			pO->PrintMessage("Invalid Value!!! Please try Again : ");
		}
	}
	return D;
}

/**
 * GetVariable - Check if the Variable Name is Valid
 *
 * Parmeters : Output *pO to print messagaes for user
 *
 * Return: Valid Variable Name
*/

string Input::GetVariable(Output* pO)
{
	string Var;
	Var = GetString(pO);
	while (IsVariable(Var) == false)
	{
		pO->PrintMessage("Invalid Variable!!! Please try Again : ");
		Var = GetString(pO);
	}

	return Var;
}

/**
 * GetArithOperator - Get the Valid ArthOperator From User
 *
 * Parmeters : Output *pO to print messagaes for user
 *
 * Return: Valid ArthOperator
*/

string Input::GetArithOperator(Output* pO)
{
	string Arth_str;

	pO->PrintMessage("Enter The Arthimetic Operator : ");
	Arth_str = GetString(pO);

	while (Arth_str.length() != 1)
	{
		pO->PrintMessage("Invalid Arithmetic Operator!!! Please try Again : ");
		Arth_str = GetString(pO);
	}

	// ASCII Code Is Used
	//  43 --> +
	//  45 --> -
	//  42 --> *
	//  47 --> / 

	while (Arth_str[0] != 43 && Arth_str[0] != 45 && Arth_str[0] != 42 && Arth_str[0] != 47)
	{
		pO->PrintMessage("Invalid Arithmetic Operator!!! Please try Again : ");
		Arth_str = GetString(pO);
	}

	return Arth_str;
}

/**
 * GetCompOperator - Get the Valid CompOperator From User
 *
 * Parmeters : Output *pO to print messagaes for user
 *
 * Return: Valid CompOperator
*/
string Input::GetCompOperator(Output* pO)
{
	string Comp_str;

	pO->PrintMessage("Enter The Compare Operator : ");
	Comp_str = GetString(pO);

	// Make Sure User Enter Exact length of Operators

	while (Comp_str.length() != 2 && Comp_str.length() != 1)
	{
		pO->PrintMessage("Invalid Comparison Operator!!! Please try Again :");
		Comp_str = GetString(pO);
	}

	// Check Which Comp Operator

	while (true)
	{
		// ASCII Code Used

		if (Comp_str[0] == 61 && Comp_str[1] == 61) // 61 --> =
			return Comp_str;

		else if (Comp_str[0] == 33 && Comp_str[1] == 61) // 33 --> ! .. 61 --> =
			return Comp_str;

		else if (Comp_str[0] == 60) // 60 --> <
			return Comp_str;

		else if (Comp_str[0] == 60 && Comp_str[1] == 61) // 60 --> < ... 61 --> =
			return Comp_str;

		else if (Comp_str[0] == 62) // 62 --> >
			return Comp_str;

		else if (Comp_str[0] == 62 && Comp_str[1] == 61) // 62 --> > ... 61 --> =
			return Comp_str;

		else
		{
			// User Entered Invalid Operator

			pO->PrintMessage("Invalid Comparison Operator!!! Please try Again :");
			Comp_str = GetString(pO);
		}
	}
}

ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on


			// Check the icon Clicked and return its Action Type

			switch (ClickedItem)
			{
				case ITM_VALUE_ASSIGN:	return ADD_VALUE_ASSIGN;
				case ITM_START:			return ADD_START;
				case ITM_END:			return ADD_END;
				case ITM_READ:			return ADD_READ;
				case ITM_WRITE:			return ADD_WRITE;
				case ITM_COND:			return ADD_CONDITION;
				case ITM_CONNECT:		return ADD_CONNECTOR;
				case ITM_SELECT:		return SELECT;
				case ITM_UNSELECT:		return UNSELECT;
				case ITM_DELETE:		return DEL;
				case ITM_COPY:			return COPY;
				case ITM_PASTE:			return PASTE;
				case ITM_SAVE:			return SAVE;
				case ITM_LOAD:			return LOAD;
				case ITM_SIM_SWITCH:	return SWITCH_SIM_MODE;
				case ITM_EXIT:			return EXIT;

				default:
					return DSN_TOOL;
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;	
			else
				return OUTPUT_AREA;
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		// User is In Simulation Mode
		// Check Clicked Item and return Its Action

		int ClickedItem = (x / UI.MenuItemWidth);
		switch (ClickedItem)
		{
			case ITM_VALIDATE:		return VALIDATE;
			case ITM_RUN:			return RUN;
			case ITM_DESIGN_SWITCH: return SWITCH_DSN_MODE;
		}

	}

}


Input::~Input()
{
}
