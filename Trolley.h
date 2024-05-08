#pragma once

#include <iostream>
#include "Transport.h"

class Trolley: public Transport {
public:
	Trolley();

	Trolley(Point, Point, size_t, double);

	Move* clone() const override;

	void print() const override;
};

