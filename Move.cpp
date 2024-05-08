#include "Move.h"

std::ostream& operator<<(std::ostream& os, const Move& move) {
	move.print();
	return os;
}

Move::Move(): _start(Point()), _end(Point()), _time(0) {}

Move::Move(Point start, Point end, size_t time): _start(start), _end(end), _time(time) {}

Point Move::get_start() const {
	return _start;
}

void Move::set_start(const Point& start) {
	_start = start;
}

Point Move::get_end() const {
	return _end;
}

void Move::set_end(const Point& end) {
	_end = end;
}

size_t Move::get_time() const {
	return _time;
}

void Move::set_time(const size_t& time) {
	_time = time;
}
