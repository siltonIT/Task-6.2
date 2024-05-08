#include "Array.h"

Array::Array(): _capacity(1), _size(0), _seq(nullptr) {}

Array::Array(const Array& other): _capacity(other._capacity), _size(other._size), _seq(new Move*[_capacity]) {	
	for(size_t i = 0; i < other._size; ++i)
		_seq[i] = other._seq[i]->clone();
}

Array& Array::operator=(Array other) {
	Array res(other);
	swap(res);

	return *this;
}

Array::Array(Array&& other) noexcept: _capacity(other._capacity), _size(other._size), _seq(other._seq) {
	other._capacity = 1;
	other._size = 0;
	other._seq = nullptr;
}

Array& Array::operator=(Array&& other) noexcept {
	Array res(std::move(other));
	swap(res);

	return *this;
}	

void Array::swap(Array& other) noexcept {
	std::swap(_capacity, other._capacity);
	std::swap(_size, other._size);
	std::swap(_seq, other._seq);
}

Array::~Array() {
	clear();
}

void Array::pop_back() {
	delete _seq[_size];
	_seq[_size] = nullptr;
	--_size;
}

void Array::print() const {
	for(size_t i = 0; i < _size; ++i)
		_seq[i]->print();
}

void Array::clear() {
	for(size_t i = 0; i < _capacity; ++i) 
		delete _seq[i];

	delete[] _seq;
	_seq = nullptr;
	_capacity = 1;
	_size = 0;
}

size_t Array::size() const {
	return _size;
}

size_t Array::capacity() const {
	return _capacity;
}

void Array::resize() {
	size_t new_capacity = _capacity * 2;
	Move** new_seq = new Move*[_capacity];
	
	for(size_t i = 0; i < _capacity; ++i) {
		new_seq[i] = _seq[i];
		_seq[i] = nullptr;
		delete _seq[i];
	}

	delete[] _seq;
	_capacity = new_capacity;
	_seq = new_seq;
}
