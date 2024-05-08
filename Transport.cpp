#include "Transport.h"

Transport::Transport(): Move(), _price(0.0) {}

Transport::Transport(Point start, Point end, size_t time, double price): Move(start, end, time), _price(price > 0 ? price : 0.0) {}

double Transport::get_price() const {
	return _price;
}

void Transport::set_price(const double& price) {
	if(price < 0)
		return;

	_price = price;
}
