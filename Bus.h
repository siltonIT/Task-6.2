#pragma once

#include <iostream> 
#include "Transport.h"

class Bus : public Transport {
public:
	Bus();

	Bus(Point, Point, size_t, double);

	Move* clone() const override;

	void print() const override;
};
