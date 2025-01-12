#pragma once

#include"..//ApplicationManager.h"
#include"..//Components/Fuse.h"

class ActionAddFuse : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	string Nam_Of_Fuse = "Defult Fuse";
	int Number_of_Fuse;
	double value_of_Fuse_Current = 0;
	bool isDamaged = false;

public:
	ActionAddFuse(ApplicationManager* pApp);
	virtual ~ActionAddFuse(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

