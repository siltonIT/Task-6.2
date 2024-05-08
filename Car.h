#pragma once                                                                                          

#include <iostream>
#include "Transport.h"
                  
class Car: public Transport {
public:
        Car();

        Car(Point, Point, size_t, double, char*);

	Car(const Car&);

	~Car() override;

	Move* clone() const override;

        void print() const override;

	char* get_path() const;
	void set_path(char*&);

private:
	char* _path;
};
