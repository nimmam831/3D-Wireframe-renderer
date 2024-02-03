//Include
#pragma warning(disable : 4996)
#include "2DVect.h"
#include "3DVect.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
//Shaders
using namespace std;
//Define color class
struct Color {
	double r;
	double g;
	double b;
};
Color shadertesting(int x, int y, int z, int height, int width) {
	//Color the pixels red
	Color* colors = new Color[1];
	colors[0].r = x % 128;
	colors[0].g = y % 192;
	colors[0].b = x + y * 2 % 46;
	return colors[0];
}
//Functions
TwoDVect project(double X, double Y, double Z, double focalLength, int width, int height) {
	double _x_ = focalLength * X / (focalLength + Z);
	double _y_ = focalLength * Y / (focalLength + Z);
	std::cout << _x_ << ' ' << _y_ << endl;
	return TwoDVect(_x_ + (width / 2), _y_ + (height / 2));
}
void line(int x0, int y0, int x1, int y1, std::vector<TwoDVect>& positions)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;

	int err = dx - dy;
	int x = x0;
	int y = y0;

	while (true)
	{
		positions.push_back(TwoDVect(x, y));

		if (x == x1 && y == y1)
			break;

		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}
void cube(ThreeDVect* positions, int width, int height, TwoDVect* projections, Color* pixels) {
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[0];
		TwoDVect end = projections[1]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[0];
		TwoDVect end = projections[2]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[0];
		TwoDVect end = projections[4]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[1];
		TwoDVect end = projections[5]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[2];
		TwoDVect end = projections[3]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[1];
		TwoDVect end = projections[3]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int point = 0; point < 8; point++) {
		TwoDVect start = projections[2];
		TwoDVect end = projections[6]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}

	// Draw a line segment from 'start' to 'end'
	for (int i = 0; i < 1; i++) {
		TwoDVect start = projections[3];
		TwoDVect end = projections[7]; // Wrap around to the first point
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}
	}
	for (int i = 0; i < 1; i++) {

		TwoDVect start = projections[7];
		TwoDVect end = projections[5]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}

	}
	for (int i = 0; i < 1; i++) {

		TwoDVect start = projections[4];
		TwoDVect end = projections[5]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}

	}
	for (int i = 0; i < 1; i++) {

		TwoDVect start = projections[6];
		TwoDVect end = projections[7]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}

	}
	for (int i = 0; i < 1; i++) {

		TwoDVect start = projections[4];
		TwoDVect end = projections[6]; // Wrap around to the first point

		// Draw a line segment from 'start' to 'end'
		std::vector<TwoDVect> positions;
		line(start.getX(), start.getY(), end.getX(), end.getY(), positions);
		for (int position = 0; position < positions.size(); position++) {
			TwoDVect projection = positions[position];
			pixels[(height - (int)projection.getY()) * width + (int)projection.getX()] = shadertesting((int)projection.getY(), (int)projection.getX(), 1, 1, 1);
		}

	}
}

void savebmp(const char* filename, int w, int h, int dpi, Color* data, int mult) {
	FILE* f;
	int k = w * h;
	int s = 4 * k;
	int filesize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi * m;
	std::cout << ppm << endl;

	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);

	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s >> 8);
	bmpinfoheader[23] = (unsigned char)(s >> 16);
	bmpinfoheader[24] = (unsigned char)(s >> 24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm >> 8);
	bmpinfoheader[27] = (unsigned char)(ppm >> 16);
	bmpinfoheader[28] = (unsigned char)(ppm >> 24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm >> 8);
	bmpinfoheader[31] = (unsigned char)(ppm >> 16);
	bmpinfoheader[32] = (unsigned char)(ppm >> 24);

	f = fopen(filename, "wb");

	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);

	for (int i = 0; i < k; i++) {
		Color rgb = data[i];

		double red = (data[i].r) * mult;
		double green = (data[i].g) * mult;
		double blue = (data[i].b) * mult;

		unsigned char color[3] = { (int)floor(blue),(int)floor(green),(int)floor(red), };
		fwrite(color, 1, 3, f);
	}
	fclose(f);
}
//Main source
int main()
{
	int thisone = 0;

	int dpi = 72;
	int width = 1280;
	int height = 720;
	int n = width * height;
	Color* pixels = new Color[n];
	ThreeDVect* points = new ThreeDVect[8];
	points[0].setXYZ(100, 100, 9);
	points[1].setXYZ(150, 100, 9);
	points[2].setXYZ(100, 150, 9);
	points[3].setXYZ(150, 150, 9);
	points[4].setXYZ(100, 100, 29);
	points[5].setXYZ(150, 100, 29);
	points[6].setXYZ(100, 150, 29);
	points[7].setXYZ(150, 150, 29);
	TwoDVect* projections = new TwoDVect[8];

	for (int i = 0; i < 8; i++) {
		TwoDVect projection = project(points[i].getX(), points[i].getY(), points[i].getZ(), 200, width, height);
		std::cout << projection.getX() * 1 << ' ' << projection.getY() * 1 << endl;
		projections[i] = projection;
	}
	cube(points, width, height, projections, pixels);
	savebmp("scene.bmp", width, height, dpi, pixels, 10);
}