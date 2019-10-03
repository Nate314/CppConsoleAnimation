#pragma once
#include "util.h"
#include<vector>
using namespace std;

// base class for all shapes
class Shape {
protected:
	// x and y position
	// width and height
	Bounds bounds;
	// matrix of pixel characters
	vector<vector<char>> pixels;
	// the character to use for this shape
	char color;
public:
	// constructors
	Shape() { };
	Shape(Bounds _bounds, char _color) {
		*this = Shape(_bounds.getLocation(), _bounds.getSize(), _color);
	};
	Shape(Point _location, Dimension _size, char _color) {
		*this = Shape(_location.getX(), _location.getY(), _size.getWidth(), _size.getHeight(), _color);
	};
	Shape(double _x, double _y, double _width, double _height, char _color) {
		this->bounds = Bounds(Point(_x, _y), Dimension(_width, _height));
		this->color = _color;
	}
	// getters
	Bounds getBounds() { return this->bounds; }
	char getColor() { return this->color; };
	char getPixel(int _x, int _y) { return this->pixels[_y][_x]; };
	void setPixels(vector<vector<char>> _pixels) { this->pixels = _pixels; };
	vector<vector<char>> getPixels() { return this->pixels; };
	/*
	// overloaded operators
	Shape operator+(Shape rhs) {
	int minX = (rhs.getX() < this->getX()) ? rhs.getX() : this->getX();
	int minY = (rhs.getY() < this->getY()) ? rhs.getY() : this->getY();
	int maxX = (rhs.getX() + rhs.getWidth() > this->getX() + this->getWidth())
	? rhs.getX() + rhs.getWidth() : this->getX() + this->getWidth();
	int maxY = (rhs.getY() + rhs.getHeight() > this->getY() + this->getHeight())
	? rhs.getY() + rhs.getHeight() : this->getY() + this->getHeight();

	Shape* result = new Shape(minX, minY, maxX - minX + 1, maxY - minY + 1, this->color);

	result->pixels.clear();
	for (int i = 0; i < result->height; i++) {
	vector<char> temp;
	for (int j = 0; j < result->width; j++) {
	temp.push_back(' ');
	}
	result->pixels.push_back(temp);
	}

	Shape shapes[] = { *this, rhs };
	for (int index = 0; index < 2; index++) {
	Shape s = shapes[index];
	vector<vector<char>>* tempPixels = new vector<vector<char>>;
	tempPixels->clear();
	for (int i = result->y; i < result->y + result->height; i++) {
	vector<char> temp;
	for (int j = result->x; j < result->x + result->width; j++) {
	if ((j >= s.getX() && j < s.getX() + s.getWidth())
	&& (i >= s.getY() && i < s.getY() + s.getHeight())) {
	if (s.getPixel(j - s.getX(), i - s.getY()) == ' ')
	temp.push_back(result->getPixel(j - s.getX(), i - s.getY()));
	else
	temp.push_back(s.getPixel(j - s.getX(), i - s.getY()));
	}
	else
	temp.push_back(result->getPixel(j - s.getX(), i - s.getY()));
	}
	tempPixels->push_back(temp);
	}
	result->pixels.clear();
	result->pixels = *tempPixels;
	delete tempPixels;
	}
	return *result;
	}
	Shape operator=(Shape rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
	this->width = rhs.width;
	this->height = rhs.height;
	this->color = rhs.color;
	this->pixels = rhs.pixels;
	return *this;
	}
	Shape operator+=(Shape rhs) {
	*this = *this + rhs;
	return *this;
	}
	*/
};
