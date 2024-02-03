#pragma once

class ThreeDVect {
	double x, y, z;
public:
	ThreeDVect();
	ThreeDVect(double, double, double);
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	void setX(double newX) { x = newX; }
	void setY(double newY) { y = newY; }
	void setZ(double newZ) { z = newZ; }
	void setXYZ(double nX, double nY, double nZ) { x = nX; y = nY; z = nZ; }
	void setXYZ(int nX, int nY, int nZ) { x = nX; y = nY; z = nZ; }
};

ThreeDVect::ThreeDVect() {
	x = 0;
	y = 0;
	z = 0;
}

ThreeDVect::ThreeDVect(double i, double j, double k) {
	x = i;
	y = j;
	z = k;
}