#pragma once
#include "Shape.h"

// extends Shape
class Rectangle : public Shape {
public:
	//constructors
	Rectangle(Bounds _bounds, char _color) {
		*this = Rectangle(_bounds.getLocation(), _bounds.getSize(), _color);
	}
	Rectangle(Point _location, Dimension _size, char _color) {
		*this = Rectangle(_location.getX(), _location.getY(), _size.getWidth(), _size.getHeight(), _color);
	}
	Rectangle(double _x, double _y, double _width, double _height, char _color) : Shape(_x, _y, _width, _height, _color) {
		// fill pixels appropriately
		pixels.clear();
		vector<char> temp;
		for (int y = 0; y < this->bounds.getHeight(); y++) {
			temp.clear();
			for (int x = 0; x < this->bounds.getWidth(); x++)
				temp.push_back(this->color);
			pixels.push_back(temp);
		}
	}
};
