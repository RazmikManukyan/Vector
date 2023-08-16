#include "Vector.h"

template <typename T>
Vector<T>::Vector()
        : m_size(0), m_capacity(0), m_arr(nullptr) {}

template <typename T>
Vector<T>::Vector(const Vector& arg) {
    m_size = arg.m_size;
    m_capacity = arg.m_capacity;
    m_arr = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; ++i) {
        m_arr[i] = arg.m_arr[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& arg) {
    if (this == &arg) {
        return *this;
    }

    delete[] m_arr;
    m_size = arg.m_size;
    m_capacity = arg.m_capacity;
    m_arr = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; ++i) {
        m_arr[i] = arg.m_arr[i];
    }

    return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& rhs) noexcept
        : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_arr(rhs.m_arr) {
    rhs.m_size = 0;
    rhs.m_capacity = 0;
    rhs.m_arr = nullptr;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initList)
    :m_size(initList.size()), m_capacity(initList.size()){
    m_arr = new T[m_capacity];
    std::copy(initList.begin(), initList.end(), m_arr);
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_arr;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (m_size == m_capacity) {
        std::size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* new_arr = new T[new_capacity];

        for (std::size_t i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = new_arr;
        m_capacity = new_capacity;
    }
    m_arr[m_size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size > 0) {
        --m_size;
    }
}

template <typename T>
void Vector<T>::resize(std::size_t new_size) {
    if (new_size > m_capacity) {
        T* new_arr = new T[new_size];
        for (std::size_t i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = new_arr;
        m_capacity = new_size;
    }

    m_size = new_size;
}

template <typename T>
void Vector<T>::print() {
    for (std::size_t i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::clear() {
    m_size = 0;
}

template<typename T>
constexpr void Vector<T>::shrink_to_fit() {
    if(m_size == m_capacity) {
        return;
    }

    int new_size = m_size + (m_size % 10);
    T* new_arr = new T[new_size];
    for(int i = 0; i < new_size; ++i) {
        new_arr[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = new_arr;
    m_capacity = new_size;
    new_arr = nullptr;
}

template<typename T>
void Vector<T>::insert(std::size_t pos, const T &val) {
    if(pos > m_size) {
        throw std::out_of_range("Invalid position for insert");
    }
    if(m_size == m_capacity) {
        resize(m_capacity * 2);
    }
    for(int i = m_size; i > pos; i--) {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[pos] = val;
    ++m_size;
}

template<typename T>
void Vector<T>::insert(std::size_t pos, const T &val, std::size_t count) {
    if (pos > m_size) {
        throw std::out_of_range("Invalid position for insert");
    }
    if (m_size + count > m_capacity) {
        resize(m_size + count);
    }
    for (std::size_t i = m_size - 1; i >= pos + count; --i) {
        m_arr[i] = m_arr[i - count];
    }

    for (std::size_t i = pos; i < pos + count; ++i) {
        m_arr[i] = val;
    }
}

template<typename T>
void Vector<T>::insert(std::size_t pos, const Vector<T> &oth) {
    if(pos > m_size) {
        throw std::out_of_range("Invalid position for insert");
    }
    std::size_t oth_size = oth.get_size();
    std::size_t new_size = this->m_size + oth_size;
    if(new_size > m_capacity) {
        resize(new_size);
    }
    std::cout << m_size << std::endl;
    for(std::size_t i = new_size - 1; i >= pos + oth_size; --i) {
        m_arr[i] = m_arr[i - oth_size];
    }

    for(std::size_t i = 0; i < oth.m_size; ++i) {
        m_arr[pos + i] = oth.m_arr[i];
    }
}

template<typename T>
void Vector<T>::remove(std::size_t pos) {
    if(pos > m_size) {
        throw std::out_of_range("Invalid position for removal");
    }

    for(std::size_t i = pos; i < m_size; ++i) {
        m_arr[i] = m_arr[i + 1];
    }

    --m_size;
}

template<typename T>
void Vector<T>::remove(std::size_t pos, std::size_t count) {
    if(pos > m_size) {
        throw std::out_of_range("Invalid position for removal");
    }

    if(count == 0) {
        return;
    }

    if(pos + count > m_size) {
        count = m_size - pos;
    }

    for(std::size_t i = pos; i < m_size - count; ++i) {
        m_arr[i] = m_arr[i + count];
    }

    m_size -= count;
}

template <typename T>
T& Vector<T>::front() {
    if (m_size == 0) {
        throw std::runtime_error("Vector is empty!");
    }
    return m_arr[0];
}

template <typename T>
const T& Vector<T>::front() const {
    if (m_size == 0) {
        throw std::runtime_error("Vector is empty!");
    }
    return m_arr[0];
}

template <typename T>
T& Vector<T>::back() {
    if (m_size == 0) {
        throw std::runtime_error("Vector is empty!");
    }
    return m_arr[m_size - 1];
}

template <typename T>
const T& Vector<T>::back() const {
    if (m_size == 0) {
        throw std::runtime_error("Vector is empty!");
    }
    return m_arr[m_size - 1];
}

template <typename T>
T* Vector<T>::data() {
    return m_arr;
}

template <typename T>
T& Vector<T>::operator[](std::size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range!");
    }
    return m_arr[index];
}

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range!");
    }
    return m_arr[index];
}

template <typename T>
T& Vector<T>::at(std::size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range!");
    }
    return m_arr[index];
}

template <typename T>
const T& Vector<T>::at(std::size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range!");
    }
    return m_arr[index];
}

template <typename T>
std::size_t Vector<T>::get_size() const {
    return m_size;
}

template <typename T>
std::size_t Vector<T>::get_capacity() const {
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

