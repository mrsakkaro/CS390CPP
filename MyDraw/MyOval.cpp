#include "Stdafx.h"
#include "MyOval.h"
IMPLEMENT_SERIAL(MyOval, Figure, 1);

MyOval::MyOval(int x0, int y0, int x1, int y1, COLORREF currentColor)
	:Figure(Figure::FigureType::Oval)
{
	controlPoints.push_back(new ControlPoint(this, x0, y0));
	controlPoints.push_back(new ControlPoint(this, x1, y1));
	curColor = currentColor;
}

MyOval::MyOval(){

}

MyOval::~MyOval()
{
}

void MyOval::draw(CDC* pDC)
{
	ControlPoint * p0 = controlPoints.at(0);
	ControlPoint * p1 = controlPoints.at(1);

	// Find minx, miny, maxx, maxy
	int minX = (p0->getX()<p1->getX()) ? p0->getX() : p1->getX();
	int minY = (p0->getY()<p1->getY()) ? p0->getY() : p1->getY();
	int maxX = (p0->getX()<p1->getX()) ? p1->getX() : p0->getX();
	int maxY = (p0->getY()<p1->getY()) ? p1->getY() : p0->getY();

	// Find cx and cy
	int rx = (maxX - minX) / 2;
	int ry = (maxY - minY) / 2;
	int cx = (maxX + minX) / 2;
	int cy = (maxY + minY) / 2;

	// Draw rectangle
	CPen pen(PS_SOLID, 0, curColor);
	CPen* pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo((maxX-minX)/2+minX,minY);

	for (float i=0; i<2*3.141592; i+=.01) {
		int x=cx+cos(i)*rx;
		int y=cy+sin(i)*ry;

		if (i == 0) {
			pDC->MoveTo(x, y);
		}
		else {
			pDC->LineTo(x, y);
		}
	}
}

bool MyOval::isCloseTo(int x, int y)
{
	ControlPoint * p0 = controlPoints.at(0);
	ControlPoint * p1 = controlPoints.at(1);

	// Find minx, miny, maxx, maxy
	int minX = (p0->getX()<p1->getX()) ? p0->getX() : p1->getX();
	int minY = (p0->getY()<p1->getY()) ? p0->getY() : p1->getY();
	int maxX = (p0->getX()<p1->getX()) ? p1->getX() : p0->getX();
	int maxY = (p0->getY()<p1->getY()) ? p1->getY() : p0->getY();

	// Find cx and cy
	int rx = (maxX - minX) / 2;
	int ry = (maxY - minY) / 2;
	int cx = (maxX + minX) / 2;
	int cy = (maxY + minY) / 2;
	
	// Check all the point, and see if it is on Oval
	int prevX, prevY, curX, curY;
	for (float i = 0; i < 2 * 3.141592; i += .01) {
		int curX = cx + cos(i)*rx;
		int curY = cy + sin(i)*ry;

		if (i != 0) {
			if (Figure::distancePointToLine(x, y, prevX, prevY, curX, curY) < Figure::smallDistance) {
				return true;
			}
		}
		prevX = curX;
		prevY = curY;
	}

	// Check if (x,y) is close to any of the borders.
	

	return false;
}

void
MyOval::setColor(COLORREF color){
	curColor = color;
}

void
MyOval::Serialize(CArchive & ar){
	Figure::Serialize(ar);
}

MyOval* MyOval::clone() const {
	return new MyOval(*this);
}
