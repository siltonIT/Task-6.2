#include "Walk.h"

Walk::Walk(): Move() {}

Walk::Walk(Point start, Point end, size_t time): Move(start, end, time) {}

Move* Walk::clone() const {
        return new Walk(*this); 
}

void Walk::print() const {
	std::cout << "Walk" << std::endl;
	std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
	std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;
	std::cout << "Route time: " << _time << " minutes" << std::endl;
}
