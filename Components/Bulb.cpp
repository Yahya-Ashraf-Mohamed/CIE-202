#include "Bulb.h"

//ApplicationManager* pManager;
//UI* pUI = pManager->GetUI();
//Bulb* pBulb = nullptr;

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->Draw_Bulb(*m_pGfxInfo, isSelected, false); //update to draw resistor

}

void Bulb::Operate() {}

Bulb::Bulb()		// no arg constructor
{
	Internal_res = 0;
	isTurn = false;
	bulb_num += 1;
}
Bulb::Bulb(double Internal_res, bool isTurn)		// Arg constructor
{
	double Internal_resistance = Internal_res;
	bool isTurnON = isTurn;
	bulb_num += 1;
}

// functions
void Bulb::setInter_Resistance()
{
	//pUI->PrintMsg("Enter the Internal Resistance: \n");
	//pUI-> GetSrting(Internal_res);
	//pUI->ClearStatusBar();
}
double Bulb::getInter_Resistance()
{
	return Internal_res;
	//pUI->ClearStatusBar();
}

bool Bulb::Display_Light()
{
	//pUI->PrintMsg("Turn on (y or n ) ? ");
	string option;
	//option = pUI->GetSrting();
	if (option == "y" || option == "Y")
		isTurn = true;
	else
		isTurn = false;
	return isTurn;
}
