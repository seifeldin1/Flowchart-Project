#include "Output.h"
#define CW 1
#define CCW -1

Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200; //1200
	UI.height = 620; //620
	UI.wx = 40; //15
	UI.wy =40; //15

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 72;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	UI.COND_WDTH = 225;
	UI.COND_HI = 85;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	ClearToolBar();			//Clears tool bar

	string MenuItemImages[DSN_ITM_CNT];	//list of image file paths for the Design bar

	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Rectangle_Equal.jpg";
	MenuItemImages[ITM_START] = "images\\Ellipse_Start.jpg";
	MenuItemImages[ITM_END] = "images\\Ellipse_End.jpg";
	MenuItemImages[ITM_READ] = "images\\Parallelogram_Read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Parallelogram_Write.jpg";
	MenuItemImages[ITM_COND] = "images\\Rhombus.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Arrow_Connector.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Select_Icon.jpg";
	MenuItemImages[ITM_UNSELECT] = "images\\Unselect_Icon.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Delete_Icon.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy_Icon.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste_Icon.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save_Button.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Load_Button.jpg";
	MenuItemImages[ITM_SIM_SWITCH] = "images\\Switch_Mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit_Button.jpg";

	//Drawing menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Drawing a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{	
	UI.AppMode = SIMULATION;	//Simulation Mode
	ClearToolBar();				//Clears tool bar

	string SimItemImages[SIM_ITM_CNT]; //list of image file paths for the simulation bar

	SimItemImages[ITM_VALIDATE] = "images\\Validate_Icon.jpg";
	SimItemImages[ITM_RUN] = "images\\Run_Icon.jpg";
	SimItemImages[ITM_DESIGN_SWITCH] = "images\\Switch_Mode.jpg";

	//Drawing menu items one image at a time
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(SimItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Drawing a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Takes a string and the shape it is in and return X,Y for centered text
void Output::CenterText(string Label, int& X, int& Y, int ShapeWidth, int ShapeHeight)
{

	int TextWidth, TextHeight;
	pWind->GetStringSize(TextWidth, TextHeight, Label);

	if (ShapeWidth - TextWidth >= 0)
		X += (ShapeWidth - TextWidth) / 2;
	if (ShapeHeight - TextHeight)
		Y += (ShapeHeight - TextHeight) / 2;

	return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawRectangle(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Calculates text position
	int X = Left.x, Y = Left.y;

	CenterText(Text, X, Y, width, height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(X, Y, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawEllipse(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Calculates text position
	int X = Left.x, Y = Left.y;

	CenterText(Text, X, Y, width, height);


	pWind->SetPen(BLACK, 2);
	pWind->DrawString(X, Y, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawRhombus(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	int* x = new int[4];		//X coords for vertices of rhombus starting from top going CCW
	x[0] = (Left.x + width/2);
	x[1] = Left.x;
	x[2] = (Left.x + width / 2);
	x[3] = Left.x + width;

	int* y = new int[4];		// Y coords for vertices of rhombus starting from top going CCW
	y[0] = Left.y;
	y[1] = (Left.y + height/2);
	y[2] = Left.y + height;
	y[3] = (Left.y + height / 2);


	pWind->DrawPolygon(x,y,4);

	//Calculates text position
	int X = Left.x, Y = Left.y;

	CenterText(Text, X, Y, width, height);

	//Draws text inside the Rhombus
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(X, Y, Text);
	delete[] x, y;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawParralellogram(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	int* x = new int[4];		//X coords for vertices of Parrallelogram starting from top left going CW
	x[0] = (Left.x + width/3);
	x[1] = Left.x + width + width/3;
	x[2] = Left.x + width;
	x[3] = Left.x;

	int* y = new int[4];		// Y coords for vertices of Parrallelogram starting from top left going CW
	y[0] = Left.y;
	y[1] = Left.y;
	y[2] = Left.y + height;
	y[3] = Left.y + height;


	pWind->DrawPolygon(x, y, 4);

	
	//Calculates text position
	int X = (Left.x+ width/6), Y = Left.y;

	CenterText(Text, X, Y, width, height);

	//Draws text inside Parrallelogram
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(X, Y, Text);
	delete[] x, y;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawConnector(Point P1, Point P2, bool Selected)
{
	
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	//This calculates the angle between the connector and an imaginary X-axis at the end point.
	double angle, slope;
	if (P2.x - P1.x != 0)
	{
		slope = ((double)(P2.y - P1.y) / (P2.x - P1.x));
		angle = atan(slope);
	}
	else
		angle = (double)INFINITY;
	bool IsUpward;
	if (P2.y < P1.y)
		IsUpward = 1;
	else
		IsUpward = 0;

	//Draws the line and call the DrawArrowfunction at the end point.
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
	DrawArrow(P2, angle,IsUpward);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawArrow(Point P, double RotationAngle, bool IsUpward)
{

	//this defines the X component and Y component for later use.
	//these define the shape of the arrow and changing them will result
	//in narrowing or elongating the arrow and vice versa.

	int Xcomp = 10;		//this should always be a positive value (increase to widen, decrease to shrink)
	int Ycomp = 20;		//this should always be a positive value (increase to lengthen, decrease to shorten)

	if (!IsUpward)
		Ycomp*=-1;

	//the 2 points that represent the arrow vertices
	//they are defaulted to our relative origin point
	//which is "P".
	Point P1, P2;
	P1.x = P.x; P1.y = P.y;
	P2.x = P.x; P2.y = P.y;

	//checks if the connector is vertical.
	if (RotationAngle != (double)INFINITY && RotationAngle != (double)-INFINITY)
	{
		int Direction;	//This dictates whether we rotate CW(1) or CCW(-1)


		//Now this part is fairly complicated so strap in.
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//	the "RotationAngle" value taken in the parameters is the angle between the X axis and the Rotated Y axis.	//
		//	due to the cartisian rotation formulas requiring the use of the angle between the X axis and Rotated X axis	//
		//	we check for whether the angle is positive (obtuse) or negative (acute) in case of it being obtuse we		//
		//	subtract pi/2 and set the direction to CCW, while for acute we add pi/2 and set the direction to CW.		//
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (RotationAngle > 0)
		{
			RotationAngle = (cdPi / 2) - RotationAngle;
			Direction = CCW;
		}
		else
		{
			RotationAngle += (cdPi / 2);
			Direction = CW;
		}

		//Nothing much to explain here this is just the Cartisian rotation formulas.
		//However here is the wiki link for them: https://en.wikipedia.org/wiki/Rotation_matrix

		P1.x += (Xcomp)*cos(RotationAngle) - Direction * (Ycomp)*sin(RotationAngle);
		P1.y += Direction * (Xcomp)*sin(RotationAngle) + (Ycomp)*cos(RotationAngle);

		P2.x += (-Xcomp) * cos(RotationAngle) - Direction * (Ycomp)*sin(RotationAngle);
		P2.y += Direction * (-Xcomp) * sin(RotationAngle) + (Ycomp)*cos(RotationAngle);
	}
	else
	{
		//When the connector is vertical the arrow defaults to this position.
		P1.x += Xcomp; P1.y += Ycomp;
		P2.x += -Xcomp; P2.y += Ycomp;
	}

	//Draws the 2 lines to form the arrow.
	pWind->DrawLine(P.x, P.y, P1.x, P1.y);
	pWind->DrawLine(P.x, P.y, P2.x, P2.y);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
