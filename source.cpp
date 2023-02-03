#include <iostream>
#include "Vector.h"

Vector::Vector()
	:m_size(0)
	,m_capacity(0)
	,m_arr(nullptr)
	{}

Vector::Vector(const Vector& arg) {
	if(this->m_arr) {
		delete[] this->m_arr;
		this->m_arr = nullptr;
	}
	this->m_size = arg.m_size;
	this->m_capacity = arg.m_capacity;
	this->m_arr = new int[this->m_capacity];
	for(int i = 0; i < this->m_size; ++i){
		this->m_arr[i] = arg.m_arr[i];
	}
}

Vector& Vector::operator=(const Vector& arg) {
	if(this->m_arr) {
		delete[] this->m_arr;
		this->m_arr = nullptr;
	} else {
		this->m_capacity = arg.m_capacity;
		this->m_size = arg.m_size;
		this->m_arr = new int[this->m_capacity];
		for(int i = 0; i < m_size; ++i){
			this->m_arr[i] = arg.m_arr[i];
		}
	}
	return *this;
}

Vector::Vector(Vector&& rhs)
	:m_size(rhs.m_size)
	,m_capacity(rhs.m_capacity)
	,m_arr(rhs.m_arr)
	{}

Vector::~Vector(){
	this->m_size = 0;
	this->m_capacity = 0;
	delete[] m_arr;
	m_arr = nullptr;
}

void Vector::push_back(int value) {
	if(!this->m_arr){
		this->m_capacity = 1;
		this->m_size = 1;
		this->m_arr = new int[this->m_size];
		this->m_arr[0] = value;
	} else {
		if(this->m_size + 1 >= this->m_capacity){
			resize(this->m_size + 1);
		}
		this->m_arr[m_size++] = value;
	}
}

void Vector::pop_back() {
	if(!this->m_arr) {
		return;
	} else if(this->m_size > 1){
		this->m_size -= 1;
	} else if(this->m_size <= 1) {
		this->m_size = 0;
		this->m_capacity = 0;
		this->m_arr = nullptr;
	}
}

void Vector::resize(int size) {
	if(!(this->m_arr)){
		this->m_capacity = size;
		this->m_arr = new int[m_capacity];
	} else {
		this->m_capacity += size;
		int* tmp = new int[this->m_capacity];
		for(int i = 0; i < this->m_size; ++i){
			tmp[i] = this->m_arr[i];
		}
		delete[] this->m_arr;
		this->m_arr = tmp;
		tmp = nullptr;
	}
}

void Vector::print() {
	for(int i = 0; i < this->m_size; ++i) {
		std::cout << m_arr[i] << ",";
	}
}

/*int& Vector::operator[](int index) throw(int){
	try{
		if(index >= 0 || index < this->m_size){
			return m_arr[index];
		} else {
			throw(index);
		}
	} catch (int e) {
			std::cout << "Exception Occured: ";
      	if(e<0)
          std::cout << "index < 0\n";
        else
          std::cout << "index >= " << this->m_size << std::endl;
        exit(1);
			}
}

int& Vector::at(int index) {
	try{
		if(index < 0 || index > this->m_size - 1) {
			throw 404;
		}	 
	}catch(...) {
		std::cout << "Access denied!";
	}
	return m_arr[index];
}*/

std::size_t Vector::size() const{
	return this->m_size;
}

std::size_t Vector::capacity() const {
	return this->m_capacity;
}

bool Vector::empty() const {
	return !(this->m_arr); 
}
