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
	Vector(Vector&& rhs);
	~Vector();

	void push_back(int);
	void resize(int);
	void print();
	int& operator[](int);
	int& at(int);

	std::size_t size() const;
	std::size_t capacity() const;
	bool empty() const; 
};

#endif

