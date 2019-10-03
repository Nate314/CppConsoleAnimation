#pragma once
#include "Panel.h"

class aTriangleDemo {
private:
	int x = 0;
	int y = 0;
	int width = 50;
	int height = 15;
	int panelWidth = 200;
	int panelHeight = 60;
	Panel panel;
public:
	aTriangleDemo(int dummy) {
		panel = Panel(0, 0, panelWidth, panelHeight);
		while (true) {
			// std::this_thread::sleep_for(std::chrono::milliseconds(500));
			panel.clear();
			update();
			panel.repaint();
		}
	}

	void update() {
		Rectangle background(0, 0, panelWidth, panelHeight, ' ');
		panel.addShape(background);
		double w = width / 2;
		double h = height / 2;
		vector<Triangle> triangles;
		triangles.push_back(Triangle(Point(width, height), Point(0, height), Point(width, 0), 'a'));
		triangles.push_back(Triangle(Point(width, height), Point(width, 0), Point(2 * width, height), 'b'));
		triangles.push_back(Triangle(Point(width, height), Point(0, height), Point(width, 2 * height), 'c'));
		triangles.push_back(Triangle(Point(width, height), Point(2 * width, height), Point(width, 2 * height), 'd'));
		triangles.push_back(Triangle(Point(width, 3 * height), Point(0, 3 * height), Point(w, 2 * height), 'e'));
		triangles.push_back(Triangle(Point(width, 3 * height), Point(0, 3 * height), Point(w, 4 * height), 'g'));
		triangles.push_back(Triangle(Point(width, 3 * height), Point(width, 2 * height), Point(2 * width, 5 * h), 'f'));
		triangles.push_back(Triangle(Point(2 * width, 4 * height), Point(2 * width, 3 * height), Point(width, 7 * h), 'h'));
		triangles.push_back(Triangle(Point(3 * width, height), Point(5 * w, 0), Point(2 * width, h), 'i'));
		triangles.push_back(Triangle(Point(3 * width, height), Point(7 * w, 0), Point(4 * width, h), 'j'));
		triangles.push_back(Triangle(Point(3 * width, height), Point(2 * width, 3 * h), Point(5 * w, 2 * height), 'k'));
		triangles.push_back(Triangle(Point(3 * width, height), Point(4 * width, 3 * h), Point(7 * w, 2 * height), 'l'));
		for (int i = 0; i < triangles.size(); i++) {
			panel.addShape(triangles[i]);
		}
		vector<Point> polyPoints;
		double pw = panelWidth / 2;
		double ph = panelHeight / 2;
		double x1 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (pw)))) + pw;
		double y1 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (ph)))) + ph;
		double x2 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (pw)))) + pw;
		double y2 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (ph)))) + ph;
		double x3 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (pw)))) + pw;
		double y3 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (ph)))) + ph;
		double x4 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (pw)))) + pw;
		double y4 = (static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (ph)))) + ph;
		Point a(x1, y1);
		Point b(x2, y2);
		Point c(x3, y3);
		Point d(x4, y4);
		polyPoints.push_back(a);
		polyPoints.push_back(b);
		polyPoints.push_back(c);
		polyPoints.push_back(d);
		Polygon polygon(polyPoints, '#');
		panel.addShape(polygon);
	}
};
