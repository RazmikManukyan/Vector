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

Vector& Vector::operator=(const Vector& rhs) {
	if(this == &rhs) {
		return *this;
	}
	Vector temp {rhs};
	std::swap (temp);
	return *this;
}

Vector::Vector(Vector&& rhs) noexcept{
		std::swap(*this, rhs);
	}

Vector& Vector::operator=(Vector&& rhs) noexcept{
	if(this == &rhs){
		return *this;
	}

	std::swap(*this, rhs);
	return *this;
}


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

void Vector::clear() {
	this->m_size = 0;
	this->m_arr = nullptr;
}

void Vector::swap(Vector& other){
	std::swap(m_size, other.m_size);
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_arr, other.m_arr);
}

void Vector::swap(Vector& first, Vector& second) {
	first.swap(second);
}

int& Vector::front(){
	if(!this->m_arr) {
		throw "Access denied!";
	}
	return m_arr[0];
}

constexpr int& Vector::front() {
	return m_arr[0];
}

const int& Vector::front() const {
	return m_arr[0];
}

constexpr const int& Vector::front() const {
	return m_arr[0];
}

int& Vector::back(){
	if(!this->m_arr) {
		throw "Access denied!";
	}
	return m_arr[m_size - 1];
}

constexpr int& Vector::back() {
	return m_arr[m_size - 1];
}

const int& Vector::back() const {
	return m_arr[m_size - 1];
}

constexpr const int& Vector::back() const {
	return m_arr[m_size - 1];
}

int* Vector::data() {
	return m_arr;
}

int& Vector::operator[](int index){
	return m_arr[index];
}

const int& Vector::operator[](int index) const {
	return m_arr[index];
}

int& Vector::at(std::size_t index) {
	if(index >= m_size) {
		throw "Access denied!";
	}
	return m_arr[index];
}

const int& Vector::at(std::size_t index) const {
	if(index >= m_size) {
		throw "Access denied!";
	}
	return m_arr[index];
}

std::size_t Vector::size() const{
	return this->m_size;
}

std::size_t Vector::capacity() const {
	return this->m_capacity;
}

bool Vector::empty() const {
	return !(this->m_arr); 
}

