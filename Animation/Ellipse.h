#pragma once
#include "Shape.h"

// extends shape
class Ellipse : public Shape {
public:
	// constructors
	Ellipse(Bounds _bounds, char _color) {
		*this = Ellipse(_bounds.getLocation(), _bounds.getSize(), _color);
	}
	Ellipse(Point _location, Dimension _size, char _color) {
		*this = Ellipse(_location.getX(), _location.getY(), _size.getWidth(), _size.getHeight(), _color);
	}
	Ellipse(double _x, double _y, double _width, double _height, char _color) : Shape(_x, _y, _width, _height, _color) {
		// fill pixels appropriately
		pixels.clear();
		vector<char> temp;
		double a = (this->bounds.getWidth() + 1) / 2;
		double b = (this->bounds.getHeight() + 1) / 2;
		for (int y = -(this->bounds.getHeight() + 1) / 2; y < (this->bounds.getHeight() + 1) / 2; y++) {
			temp.clear();
			for (int x = -(this->bounds.getWidth() + 1) / 2; x < (this->bounds.getWidth() + 1) / 2; x++) {
				double num = ((x * x) / (a * a)) + ((y * y) / (b * b));
				if (num < 1) temp.push_back(this->color);
				else temp.push_back(' ');
			}
			pixels.push_back(temp);
		}
	}
};
