#pragma once

// holds an x and y double
class Point {
private:
	// x and y of this Point
	double x, y;
public:
	// constructors
	Point() { *this = Point(-1, -1); };
	Point(double _x, double _y) {
		this->x = _x;
		this->y = _y;
	}

	// getters
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
};

// holds a width and height double
class Dimension {
private:
	// width and height of this Dimension
	double width, height;
public:
	// constructors
	Dimension() { *this = Dimension(-1, -1); };
	Dimension(double _width, double _height) {
		this->width = _width;
		this->height = _height;
	}

	// getters
	double getWidth() {
		return width;
	}
	double getHeight() {
		return height;
	}
};

// Bound is a rectangular area defined by a Point and a Dimension
class Bounds {
private:
	Point location;
	Dimension size;
public:
	// constructors
	Bounds() { *this = Bounds(Point(), Dimension()); };
	Bounds(Point _location, Dimension _size) {
		this->location = _location;
		this->size = _size;
	}

	// getters
	Point getLocation() {
		return this->location;
	}
	Dimension getSize() {
		return this->size;
	}
	double getX() {
		return this->location.getX();
	}
	double getY() {
		return this->location.getY();
	}
	double getWidth() {
		return this->size.getWidth();
	}
	double getHeight() {
		return this->size.getHeight();
	}
};

namespace util {

	// returns the maximum of the two values passed
	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}

	// returns the maximum of the three values passed
	int max(int a, int b, int c) {
		return max(max(a, b), c);
	}

	// returns the maximum value of the array passed
	int max(const int nums[], const int size) {
		int m = nums[0];
		for (int i = 1; i < size; i++) {
			m = max(m, nums[i]);
		}
		return m;
	}

	// returns the minimum of the two values passed
	int min(int a, int b) {
		if (a < b) return a;
		else return b;
	}

	// returns the minimum of the three values passed
	int min(int a, int b, int c) {
		return min(min(a, b), c);
	}

	// returns the minimum value of the array passed
	int min(const int nums[], const int size) {
		int m = nums[0];
		for (int i = 1; i < size; i++) {
			m = min(m, nums[i]);
		}
		return m;
	}

	// returns the slope calculated with the passed values
	double getSlope(double x1, double y1, double x2, double y2) {
		return (y2 - y1) / (x2 - x1);
	}

	// returns the slope between the two points passed
	double getSlope(Point p1, Point p2) {
		return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	}

	// returns the y value of the function defined by
	// y = mx + b
	double getLine(double m, double x, double b) {
		return (m * x) + b;
	}

	// returns the y value of the function defined by
	// y - b = m(x - a)
	// where m = slope(p1, p2)
	//		 a = p1.getX()
	//		 b = p1.getY()
	double getLine(Point p1, Point p2, double x) {
		double _m = getSlope(p1, p2);
		double _x = x - p1.getX();
		double _b = p1.getY();
		return getLine(_m, _x, _b);
	}

	// an Area is a line with a shaded area on one side
	class Area {
	private:
		// is this bound a vertical line?
		// is this bound an upper bound?
		bool isVertical, isUpperBound;
		// y = mx + b
		double m, b;
		// the two points that define this bound
		Point p1, p2;
	public:
		//constructor
		Area(Point _p1, Point _p2, Point other) {
			p1 = _p1;
			p2 = _p2;
			// horizontal line
			if (p1.getY() == p2.getY()) {
				isVertical = false; // horizontal is not vertical
				m = 0; // slope is 0
				b = p1.getY(); // y is constant
				isUpperBound = (other.getY() < b);
			}
			// vertical line
			else if (p1.getX() == p2.getX()) {
				isVertical = true; // vertical is vertical
				m = 0; // slope undefined
				b = 0; // y-intercept doesn't exist
				isUpperBound = (other.getX() > p1.getX());
			}
			// diagonal line
			else {
				isVertical = false; // diagonal is not vertical
				m = slope(); // slope = slope()
				b = p1.getY() - (m * p1.getX()); // calculate b
				isUpperBound = (other.getY() <= line(other.getX()));
			}
		}

		// getters
		double getm() { return m; };
		double getb() { return b; };

		// util interface functions
		double slope() { return getSlope(p1, p2); };
		double line(double x) { return getLine(m, x, b); };

		// is Point p included in this Bound?
		bool includes(Point p) {
			if (isVertical)
				if (isUpperBound) return (p.getX() >= p1.getX());
				else return (p.getX() <= p1.getX());
			else if (isUpperBound)
				return (p.getY() <= line(p.getX()));
			else
				return (p.getY() >= line(p.getX()));
		}
	};
};
