#pragma once

#include <iostream>

struct Point {
	double _x;
	double _y;
	
	Point();

	Point(double, double);

	Point(const Point&) = default;
};
