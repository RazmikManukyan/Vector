#ifndef Vector_h
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
	~Vector();

	void push_back(int);
	void pop_back();
	void resize(int);
	void print();
	//int& operator[](int) throw(int);
	//int& at(int);

	std::size_t size() const;
	std::size_t capacity() const;
	bool empty() const; 
};

#endif



