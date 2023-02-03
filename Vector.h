#ifndef Vector_h
#define Vector_h

class Vector {
private:
	std::size_t m_size;
	std::size_t  m_capacity;
	int* m_arr;
public:
	Vector();
	Vector(const Vector& arg);
	Vector& operator=(const Vector& arg);
	~Vector();

	bool empty() const; 
};
