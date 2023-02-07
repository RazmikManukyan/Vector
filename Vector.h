#ifndef Vector_h
#include <cstddef>
#define Vector_h

class Vector {
private:
	std::size_t m_size;
	std::size_t  m_capacity;
	int* m_arr;
public:
	Vector();
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	Vector(Vector&&);
	Vector& operator=(Vector&&);
	Vector(std::initializer_list<int>);
	~Vector();

	void push_back(int);
	void pop_back();
	void resize(int);
	void print();
	void clear();
	void swap(Vector&);
	void swap(Vector&, Vector&);
	int& front();
	int& back();
	int* data();
	int& operator[](int);
	const int& operator[](int) const;
	int& at(std::size_t);
	const int& at(std::size_t) const;
	int& operator->() const;
	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	bool operator>(const Vector&);
	std::size_t size() const;
	std::size_t capacity() const;
	bool empty() const; 

	public:
		class iterator {
			public:
				iterator(int* ptr):m_iterator(ptr){}
				
			private:
				int* m_iterator;
		};	
};

#endif





