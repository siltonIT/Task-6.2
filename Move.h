#pragma once

#include <iostream>
#include <ostream>
#include "Point.h"

#define size_t unsigned int

class Move {
	friend std::ostream& operator<<(std::ostream&, const Move&);

public:
	Move();

	Move(Point, Point, size_t);

	virtual ~Move() = default;

	virtual void print() const = 0;

	virtual Move* clone() const = 0;

	Point get_start() const;
	void set_start(const Point&);

	Point get_end() const;
	void set_end(const Point&);

	size_t get_time() const;
	void set_time(const size_t&);

protected:
	Point _start;
	Point _end;

	size_t _time;
};
