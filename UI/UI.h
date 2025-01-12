#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"


#include <string>
using namespace std;

// to do line 151 (connection), 130 (check valid) 

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component/connection
//Each component stores its drawing points in this struct 
//For example, a resistor can store points of the rectangluar area it occupies
//The Connection can store the points of its line segments
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}

};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,			     //Resistor item in menu
		ITM_Battery,		     // Battery item in menu
		ITM_Switch,		         // Switch item in menu 
		ITM_Bulb,				 // Bulb item in menu
		ITM_Ground,		         // Ground item in menu
		ITM_Buzzer,				 // Buzzer item in menu 
		ITM_Fuse,			     // Fuse item in menu
		ITM_ADD_CONNECTION,		 //Add Connection in menu

		Group_ChangeSwitch_And_Save, // upper click Change Switch case on/off || Lower click save the circuit
		Group_Module_And_Load,       // upper click select the componnent  || Lower click Load the saved circuit
		Group_Move_And_Undo,         // Upper click Moves the combonnent || Lower click undo the last Action
		Group_Lable_And_Redo,        // Upper click Lable the selected componnent || Lower click Resdo the last Action
		Group_EditLable_And_Delete,  // Upper click Edit the lable of the selected combonnent || Lower click Delete the selected componnent

		Change_Mode_Simulation,      // Changes App mode from design to simulation 

		ITM_EXIT_Design,			 // Exit item
	
		ITM_DSN_CNT					 //no. of design menu items ==> This should be the last line in this enum
	
	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_Start_SIM,			//Start Simulate item
		ITM_Stop_SIM,			//Stop simulation
		ChangeSwitch_ON_OFF,    //Change the switch state On/Off
		Select,					//Select the clicked componnent 
		Ammeter,				//Ammeter showes the current intensity (I)
		Voltmeter,				//Voltmeter showes the current intensity (I)
		Change_Mode_Design,		//Switchs to design mood
		ITM_EXIT_Simulation,	//Exit item

		ITM_SIM_CNT				//no. of simulation menu items ==> This should be the last line in this enum
	
	};


	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1216, height = 630,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80,		//Width of each item in toolbar menu

						//Arbitrary values, you can change as you wish
						COMP_WIDTH = 50,		//Component Image width
						COMP_HEIGHT = 20;		//Component Image height

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color



	window *pWind;
	
public:
	
	UI();
	int getCompWidth() const;	//returns Component width
	int getCompHeight() const;	//returns Component height
	int getToolBarHeight() const;
	int getStatusBarHeight() const;
	int	getWindowHeight() const;
	MODE GetAppMode()const;     //returns App Mode state
	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);		//Get coordinate where user clicks
	string GetSrting();						//Returns a string entered by the user

	ActionType GetUserAction() const;		//Reads the user click and maps it to an action
	
	void GetClickLocation(int& x, int& y);  //Reads the location where the user clicked

	window* GetpWind();

	void SetAppMode(MODE);
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const; //Change the title of the application

	void CreateDesignToolBar();			  //Tool bar of the design mode
	void CreateSimulationToolBar();		  //Tool bar of the simulation mode
	void CreateStatusBar() const;		  //Create Status bar

	void ClearStatusBar() const;	      //Clears the status bar
	void ClearDrawingArea() const;		  //Clears the drawing area
	void ClearToolBar() const;			  //Clears toolbar

	bool Check_Valid(int x,int y)const;	  // This Function prevent the user to draw any where exept in Design area
	
	// To do : Function check if the place where user clicked in the design area empty to draw the componnent or not
	// To do : Function check if the place where the two component will be connected in the design area empty to draw the conection or not

	// Draws a resistor function
	void Draw_Resistor(const GraphicsInfo &r_GfxInfo, bool selected) const;
	// Draws a battery function
	void Draw_Battery(const GraphicsInfo& r_GfxInfo, bool selected) const;

	// Draws a Switch function
	void Draw_Switch(const GraphicsInfo& r_GfxInfo, bool selected, bool isOn) const;

	// Draws On Bulb function
	void Draw_Bulb(const GraphicsInfo& r_GfxInfo, bool selected, bool isOn) const;

	// Draws a Ground function
	void Draw_Ground(const GraphicsInfo& r_GfxInfo, bool selected) const;
	// Draws a Buzzer function
	void Draw_Buzzer(const GraphicsInfo& r_GfxInfo, bool selected) const;
	// Draws a Fuse function
	void Draw_Fuse(const GraphicsInfo& r_GfxInfo, bool selected, bool isDameged) const;
	//Draw module
	void Draw_Module(const GraphicsInfo& r_GfxInfo, bool selected) const;

	// Draws Connection function   // to be completed soon
	void DrawConnection(const GraphicsInfo &Comp1_GfxInfo, const GraphicsInfo& Comp2_GfxInfo, bool selected) const;
	// Draws Connection
	//void DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar

	~UI();
};

#endif