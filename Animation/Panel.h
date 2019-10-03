#pragma once
#include "Shape.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

// does the rendering and such
class Panel : Shape {
private:
	// draws pixels (or chars) on console
	void paint() {
		string buffer = "";
		for (int i = 0; i < this->bounds.getHeight(); i++) {
			for (int j = 0; j < this->bounds.getWidth(); j++) {
				buffer += this->getPixel(j, i);
			}
			buffer += "\n";
		}
		system("CLS");
		printf(buffer.c_str());
		//cout << buffer;
	}
public:
	// constructors
	Panel() {
		Panel(0, 0, 80, 20);
	}
	Panel(Bounds _bounds) {
		*this = Panel(_bounds.getLocation(), _bounds.getSize());
	}
	Panel(Point _location, Dimension _size) {
		*this = Panel(_location.getX(), _location.getY(), _size.getWidth(), _size.getHeight());
	}
	Panel(double _x, double _y, double _width, double _height) {
		// set vars
		this->bounds = Bounds(Point(_x, _y), Dimension(_width, _height));
		// clear pixel array
		this->clear();
	}

	// adds a shape to this Panel
	void addShape(Shape s) {
		vector<vector<char>>* tempPixels = new vector<vector<char>>;
		tempPixels->clear();
		for (int i = 0; i < this->bounds.getHeight(); i++) {
			vector<char> temp;
			for (int j = 0; j < this->bounds.getWidth(); j++) {
				if ((j >= s.getBounds().getX() && j < s.getBounds().getX() + s.getBounds().getWidth())
					&& (i >= s.getBounds().getY() && i < s.getBounds().getY() + s.getBounds().getHeight())) {
					if (s.getPixel(j - s.getBounds().getX(), i - s.getBounds().getY()) == ' ')
						temp.push_back(this->getPixel(j, i));
					else
						temp.push_back(s.getPixel(j - s.getBounds().getX(), i - s.getBounds().getY()));
				}
				else
					temp.push_back(this->getPixel(j, i));
			}
			tempPixels->push_back(temp);
		}
		pixels.clear();
		pixels = *tempPixels;
		delete tempPixels;
	}

	// adds a polygon to this panel one triangle at a time
	void addShape(Polygon polygon) {
		for (int i = 0; i < polygon.getTriangles().size(); i++) {
			addShape(polygon.getTriangles()[i]);
		}
	}

	// sets all pixels on this Panel to ' '
	void clear() {
		pixels.clear();
		for (int i = 0; i < this->bounds.getHeight(); i++) {
			vector<char> temp;
			for (int j = 0; j < this->bounds.getWidth(); j++) {
				temp.push_back(' ');
			}
			pixels.push_back(temp);
		}
	}

	// public method used to refresh Panel
	void repaint() {
		paint();
	}
};