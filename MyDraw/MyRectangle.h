#pragma once
#include "Figure.h"
class MyRectangle :
	public Figure
{
public:
	MyRectangle(int x0, int y0, int x1, int y1, COLORREF currentColor);
	MyRectangle();
	~MyRectangle();

	DECLARE_SERIAL(MyRectangle);

	// Declaire current color variable
	COLORREF curColor;

	// Draw a rectangle using graphic context pDC
	void draw(CDC* pDC);

	// Return true if rectangle is close to coordinates (x,y)
	bool isCloseTo(int x, int y);

	void setColor(COLORREF color);

	void Serialize(CArchive & ar);

	MyRectangle* clone() const;
};

