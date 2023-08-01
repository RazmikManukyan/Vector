#ifndef Vector_h
#define Vector_h
#include <iostream>

template <typename T>
class Vector {
private:
    std::size_t m_size;
    std::size_t m_capacity;
    T* m_arr;

public:
    Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    Vector(Vector&&);
    ~Vector();

    void push_back(const T&);
    void pop_back();
    void resize(std::size_t);
    void print();
    void clear();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data();
    T& operator[](std::size_t);
    const T& operator[](std::size_t) const;
    T& at(std::size_t);
    const T& at(std::size_t) const;

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] std::size_t capacity() const;
    [[nodiscard]] bool empty() const;

public:
    class iterator {
    public:
        explicit iterator(T* ptr) : ptr(ptr) {}

        T& operator*() const {
            return *ptr;
        }

        T* operator->() const {
            return ptr;
        }

        iterator& operator++() {
            ++ptr;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++ptr;
            return temp;
        }

        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

    private:
        T* ptr;
    };

    iterator begin() {
        return iterator(m_arr);
    }

    iterator end() {
        return iterator(m_arr + m_size);
    }
};

#endif