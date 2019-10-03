#pragma once
#include "Shape.h"
#include "Triangle.h"

// extends Shape
class Polygon : public Shape {
private:
	// list of all Triangle objects that make up this Polygon
	vector<Triangle> triangles;
public:
	// recursively add Triangle objects to vector
	void addTriangles(vector<Point> points, char color) {
		// if there are more than three points
		if (points.size() > 3) {
			// add the first three points as a Triangle to the list of Triangle objects
			triangles.push_back(Triangle(points[0], points[1], points[2], color));
			// make a new list not including the point used
			// for the current Triangle being added
			vector<Point> theRestOfThePoints;
			theRestOfThePoints.push_back(points[0]);
			theRestOfThePoints.push_back(points[2]);
			for (int i = 3; i < points.size(); i++)
				theRestOfThePoints.push_back(points[i]);
			// recursive call
			addTriangles(theRestOfThePoints, color);
		}
		// when there are only three points left
		else triangles.push_back(Triangle(points[0], points[1], points[2], color));
	}

	Polygon(vector<Point> points, char _color) {
		// populate list with Triangles that make up this Polygon
		addTriangles(points, _color);
		// find and set x, y, width, height, and color for this Shape
		int minX, minY, maxX, maxY;
		minX = triangles[0].getBounds().getX();
		minY = triangles[0].getBounds().getY();
		maxX = minX + triangles[0].getBounds().getWidth();
		maxY = minY + triangles[0].getBounds().getHeight();
		for (Shape s : triangles) {
			minX = util::min(minX, s.getBounds().getX());
			minY = util::min(minY, s.getBounds().getY());
			maxX = util::max(maxX, s.getBounds().getX() + s.getBounds().getWidth());
			maxY = util::max(maxY, s.getBounds().getY() + s.getBounds().getHeight());
		}
		this->bounds = Bounds(Point(minX, minY), Dimension(maxX - minX + 1, maxY - minY + 1));
		this->color = _color;
	}

	// triangles getter
	vector<Triangle> getTriangles() {
		return triangles;
	}
};
