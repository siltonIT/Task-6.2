#pragma once

#include <iostream>
#include "Transport.h"

class Metro: public Transport {
public:
	Metro();

	Metro(Point, Point, size_t, double);

	Move* clone() const override;

	void print() const override;
};
