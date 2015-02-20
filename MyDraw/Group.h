#pragma once
#include "Figure.h"
class Group :
	public Figure
{
public:
	Group(vector<Figure *> figs);
	Group();
	~Group();

	Group(const Group &);

	DECLARE_SERIAL(Group);

	// Draw a group using graphic context pDC
	void draw(CDC* pDC);

	// Return true if group is close to coordinates (x,y)
	bool isCloseTo(int x, int y);

	// Move the control points that are selected an increment dx,dy
	void Group::dragSelectedControlPoints(int dx, int dy);

	vector<Figure*> getGroup();

	void setColor(COLORREF color);

	void Serialize(CArchive & ar);

	// Clone Group
	Group* clone() const;

private:
	// This is the list of all the figures in the Group
	vector<Figure*> groups;
	vector<ControlPoint*> groupControlPoints;
};

