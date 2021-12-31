#include "ActionAddBulb.h"
#include "..\ApplicationManager.h"


ActionAddBulb::ActionAddBulb(ApplicationManager* pApp):Action(pApp){}



ActionAddBulb::~ActionAddBulb(void)
{
}

void ActionAddBulb::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Bulb: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	// getting the resistance of the bulb 
	pUI->PrintMsg("Enter the Internal Resistance of bulb: ");
	internal_resistance = stod(pUI->GetSrting());

	if (pUI->Check_Valid(Cx, Cy) == true)
	{

		//Clear Status Bar
		pUI->ClearStatusBar();


		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

		Bulb* pR = new Bulb(pGInfo, internal_resistance);
		pManager->AddComponent(pR);
	}
	else {
		pUI->PrintMsg("Unable to draw here!");
	}

}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}


