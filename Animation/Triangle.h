#pragma once

// extends Shape
class Triangle : public Shape {
public:
	Triangle(Point p1, Point p2, Point p3, char _color) {
		// find and set x, y, width, height, and color for this Shape
		int minX, minY, maxX, maxY;
		minX = util::min(util::min(p1.getX(), p2.getX()), p3.getX());
		minY = util::min(util::min(p1.getY(), p2.getY()), p3.getY());
		maxX = util::max(util::max(p1.getX(), p2.getX()), p3.getX());
		maxY = util::max(util::max(p1.getY(), p2.getY()), p3.getY());
		this->bounds = Bounds(Point(minX, minY), Dimension(maxX - minX + 1, maxY - minY + 1));
		this->color = _color;
		// these three Bound objects define this Triangle
		util::Area a1(p1, p2, p3);
		util::Area a2(p1, p3, p2);
		util::Area a3(p2, p3, p1);
		// fill pixels appropriately
		pixels.clear();
		vector<char> temp;
		if (a1.getb() == a2.getb()
			&& a1.getb() == a3.getb()
			&& a1.getm() == a2.getm()
			&& a1.getm() == a3.getm()) {
			for (int i = minY; i <= maxY; i++) {
				temp.clear();
				for (int j = minX; j <= maxX; j++)
				{
					Point p(j, i);
					if (i == a1.line(j))
						temp.push_back(color);
					else
						temp.push_back(' ');
				}
				pixels.push_back(temp);
			}
		}
		else {
			for (int i = minY; i <= maxY; i++) {
				temp.clear();
				for (int j = minX; j <= maxX; j++)
				{
					Point p(j, i);
					if (a1.includes(p) && a2.includes(p) && a3.includes(p))
						temp.push_back(color);
					else
						temp.push_back(' ');
				}
				pixels.push_back(temp);
			}
		}
	}
};
