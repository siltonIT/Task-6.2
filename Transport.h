#pragma once

#include <iostream>
#include "Move.h"

class Transport: public Move {
public:
	Transport();

	Transport(Point, Point, size_t, double);

	virtual ~Transport() = default;

	double get_price() const;
	void set_price(const double&);

protected: 
	double _price;
};
