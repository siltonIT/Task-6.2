#pragma once

#include <iostream>
#include "Transport.h"
                  
class Taxi: public Transport {
public:
	Taxi();

        Taxi(Point, Point, size_t, double);

	Move* clone() const override;

        void print() const override;
};
