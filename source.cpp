#include <iostream>
#include "Vector.h"

Vector::Vector(){
	m_size = 0;
	m_capacity = 15;
	m_arr = nullptr;
}

Vector::Vector(const Vector& arg) {
	if(this == &arg) {
		return *this;
	}
	this->m_size = arg.size;
	this->m_capasity = arg.capacity;
	arg.arr = new int[this->m_size];
	for(int i = 0; i < this->m_size; ++i) {
		this->arr[i] = arg.arr[i];
	}
	return arg;
}

