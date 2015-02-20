#include "stdafx.h"
#include "Group.h"

IMPLEMENT_SERIAL(Group, Figure, 1);

Group::Group(vector<Figure *> figs)
	:Figure(Figure::FigureType::Group)
{
	groups = figs;

	int minX, maxX, minY, maxY;

	for each (Figure * figure in groups) {
		for each (ControlPoint * cp in figure->getControlPoints()) {
			groupControlPoints.push_back(cp);
		}
	}
	minX = groupControlPoints.at(0)->getX();
	maxX = groupControlPoints.at(0)->getX();
	minY = groupControlPoints.at(0)->getY();
	maxY = groupControlPoints.at(0)->getY();
	for each (ControlPoint * cp in groupControlPoints) {
		if (minX > cp->getX()) {
			minX = cp->getX();
		}
		if (minY > cp->getY()) {
			minY = cp->getY();
		} 
		if (maxX < cp->getX()) {
			maxX = cp->getX();
		}
		if (maxY < cp->getY()) {
			maxY = cp->getY();
		}
	}
	groupControlPoints.clear();
	controlPoints.push_back(new ControlPoint(this, minX, minY));
	controlPoints.push_back(new ControlPoint(this, maxX, maxY));
}

Group::Group(){
	figureType = FigureType::Group;
}

void
Group::Serialize(CArchive & ar) {
	Figure::Serialize(ar);

	if (ar.IsStoring()) {
		ar << figureType;
		ar << groups.size(); 
		for (auto grr : groups) {
			ar << grr;
		}
	}
	else {
		int size;
		int foo;
		ar >> foo;
		figureType = (FigureType)foo;
		ar >> size;
		for (unsigned i = 0; i < size; i++) {
			Figure * f;
			ar >> f;
			groups.push_back(f);
		}
		int minX, maxX, minY, maxY;

		for each (Figure * figure in groups) {
			for each (ControlPoint * cp in figure->getControlPoints()) {
				groupControlPoints.push_back(cp);
			}
		}
		minX = groupControlPoints.at(0)->getX();
		maxX = groupControlPoints.at(0)->getX();
		minY = groupControlPoints.at(0)->getY();
		maxY = groupControlPoints.at(0)->getY();
		for each (ControlPoint * cp in groupControlPoints) {
			if (minX > cp->getX()) {
				minX = cp->getX();
			}
			if (minY > cp->getY()) {
				minY = cp->getY();
			}
			if (maxX < cp->getX()) {
				maxX = cp->getX();
			}
			if (maxY < cp->getY()) {
				maxY = cp->getY();
			}
		}
		groupControlPoints.clear();
		controlPoints.push_back(new ControlPoint(this, minX, minY));
		controlPoints.push_back(new ControlPoint(this, maxX, maxY));
	}
}

Group::Group(const Group & virt) {
	figureType = virt.figureType;
	curColor = virt.curColor;

	for (unsigned i = 0; i < virt.groups.size(); i++) {
		groups.push_back(virt.groups.at(i)->clone());
	}

	for (unsigned i = 0; i < virt.groupControlPoints.size(); i++) {
		ControlPoint * cp = virt.groupControlPoints.at(i);
		ControlPoint * copy = new ControlPoint(this, cp->getX(), cp->getY());
		groupControlPoints.push_back(copy);
	}

	for (int i = 0; i < virt.controlPoints.size(); i++){
		ControlPoint * cp = virt.controlPoints.at(i);
		ControlPoint * copy = new ControlPoint(this, cp->getX(), cp->getY());
		controlPoints.push_back(copy);
	}
}


Group::~Group()
{
	Figure * f;
	std::vector<int>::size_type counter = 0;
	for (unsigned i = 0; i < groups.size(); i++) {
		f = groups[counter];
		groups.erase(groups.begin() + counter);
		delete f;
	}
}

void
Group::draw(CDC* pDC){
	for (unsigned i = 0; i < groups.size(); i++) {
		groups.at(i)->draw(pDC);
	}
}

bool
Group::isCloseTo(int x, int y) {
	for (unsigned i = 0; i < groups.size(); i++) {
		if (groups.at(i)->isCloseTo(x,y)) {
			return TRUE;
		}
	}
	return FALSE;
}

vector<Figure*>
Group::getGroup(){
	return groups;
}

void
Group::setColor(COLORREF color) {
	for (unsigned i = 0; i < groups.size(); i++) {
		groups.at(i)->setColor(color);
	}
}


void Group::dragSelectedControlPoints(int dx, int dy)
{
	double wP;
	double hP; 
	double mLX, mRX, mLY, mRY;
	double xLeftPercent, xRightPercent;
	double yLeftPercent, yRightPercent;
	int xL = controlPoints.at(0)->getX();
	int yL = controlPoints.at(0)->getY();
	int xR = controlPoints.at(1)->getX();
	int yR = controlPoints.at(1)->getY();
	bool left = false, right = false;
	for (unsigned i = 0; i < this->controlPoints.size(); i++) {
		ControlPoint * c = controlPoints.at(i);

		if (c->isSelected()) {
			if (i == 0) {
				left = true;
			} if (i == 1) {
				right = true;
			}
		}
	}
	if (left && right) {
		for each (ControlPoint* c in controlPoints) {
			c->move(c->getX() + dx, c->getY() + dy);
		}
		for each (Figure * figure in groups) {
			figure->select(TRUE);
			figure->dragSelectedControlPoints(dx, dy);
			figure->select(FALSE);
		/*	for each (ControlPoint* cp in figure->getControlPoints()){
				cp->move(cp->getX() + dx, cp->getY() + dy);
			}
			*/
		}
	}
	else if (left || right)
	{
		if (left) {
			controlPoints.at(0)->move(controlPoints.at(0)->getX() + dx, controlPoints.at(0)->getY() + dy);
		}
		if (right) {
			controlPoints.at(1)->move(controlPoints.at(1)->getX() + dx, controlPoints.at(1)->getY() + dy);
		}
		
		for each (Figure * figure in groups) {
			mLX = (double)abs(((xR + dx) - xL));


			mRY = (double)abs(((yR + dy) - yL));
			if (left) {
				xLeftPercent = ((double)((xL - figure->getControlPoints().at(0)->getX()))) / (double)((xR - xL));
				yLeftPercent = ((double)((figure->getControlPoints().at(0)->getY() - yL))) / (double)((yR - yL));

				figure->getControlPoints().at(0)->move(round(xLeftPercent * mLX) + xL, yL - round(yLeftPercent * mRY));

			}

			if (right) {

				yRightPercent = ((double)((yR - figure->getControlPoints().at(1)->getY()))) / (double)((yR - yL));
				xRightPercent = ((double)((figure->getControlPoints().at(1)->getX() - xR))) / (double)((xR - xL));
				figure->getControlPoints().at(1)->move(xR - round(xRightPercent * mLX), yR + round(yRightPercent * mRY));
			}
		}
	}
}

Group* Group::clone() const {
	return (new Group(*this));
}