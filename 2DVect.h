#pragma once

class TwoDVect {
	double x, y;
public:
	TwoDVect();
	TwoDVect(double, double);
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double newX) { x = newX; }
	void setY(double newY) { y = newY; }
};

TwoDVect::TwoDVect() {
	x = 0;
	y = 0;
}

TwoDVect::TwoDVect(double j, double i) {
	x = j;
	y = i;
}