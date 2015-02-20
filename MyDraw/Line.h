#pragma once

#include "Figure.h"



// Subclass for a Line. 
// Inherits most methods from Figure. 
class Line : public Figure
{
public:
	// Constructor/destructor for a line
	Line(int x0, int y0, int x1, int y1, COLORREF currentColor);
	Line();
	~Line(void);

	DECLARE_SERIAL(Line);

	// Declaire current color variable
	COLORREF curColor;

	// Draw a line using graphic context pDC
	void draw(CDC* pDC);

	// Variables to hold for clone
	int xO, xD, yO, yD;

	// Return true if line can be selected by clicking on coordinates (x,y)
	//bool selectFigureAt(int x, int y);

	// Return true if line is close to coordinates (x,y)
	bool isCloseTo(int x, int y);

	void setColor(COLORREF color);

	void Serialize(CArchive & ar);

	Line* clone() const;
};

