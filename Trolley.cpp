#include "Trolley.h"

Trolley::Trolley(): Transport() {}

Trolley::Trolley(Point start, Point end, size_t time, double price): Transport(start, end, time, price) {}

Move* Trolley::clone() const {
        return new Trolley(*this); 
}

void Trolley::print() const {
	std::cout << "Trolley" << std::endl;
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;                                                                                                        
	std::cout << "Price: " << _price << " rub" << std::endl;
	std::cout << "Route time: " << _time << " minutes" << std::endl;
}

