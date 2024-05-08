#include "Taxi.h"

Taxi::Taxi(): Transport() {}

Taxi::Taxi(Point start, Point end, size_t time, double price): Transport(start, end, time, price) {}

Move* Taxi::clone() const {
        return new Taxi(*this); 
}

void Taxi::print() const {
        std::cout << "Taxi" << std::endl;                                                                
        std::cout << "Start position: " << _start._x << ' ' << _start._y << std::endl;
        std::cout << "End position: " << _end._x << ' ' << _end._y << std::endl;                                                                                                        
        std::cout << "Price: " << _price << " rub" << std::endl;                  
        std::cout << "Route time: " << _time << " minutes" << std::endl; 
}

