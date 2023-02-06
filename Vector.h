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
	Vector(Vector&&) noexcept;
	Vector& operator=(Vector&&) noexcept;
	~Vector();

	void push_back(int);
	void pop_back();
	void resize(int);
	void print();
	void clear();
	void swap(Vector&);
	void swap(Vector&, Vector&);
	int& front();
	constexpr int& front();
	const int& front() const;
	constexpr const int& front() const;
	int& back();
	constexpr int& back();
	const int& back() const;
	constexpr const int& back() const;
	int* data();
	int& operator[](int);
	const int& operator[](int) const;
	int& at(std::size_t);
	const int& at(std::size_t) const;

	std::size_t size() const;
	std::size_t capacity() const;
	bool empty() const; 

	public:
		class iterator {
			public:
				iterator(int* ptr):ptr(ptr){}
				
			private:
				int* ptr;
		};	
};

#endif





