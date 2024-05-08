#pragma once

#include <iostream>
#include "Move.h"

class Walk: public Move {
public:
	Walk();
	
	Walk(Point, Point, size_t);

	Move* clone() const override;

	void print() const override;
};
