# Vector Template Class

The `Vector` template class is a dynamic array implementation that allows you to store and manipulate a sequence of elements of any data type. It provides functionality similar to the standard `std::vector` in C++.

## Usage

To use the `Vector` template class, include the "Vector.h" header file in your C++ project.

```cpp
#include "Vector.h"
```

### Creating a Vector

To create a `Vector` object, use the template syntax and specify the data type you want to store in the vector. For example, to create a vector of integers:

```cpp
Vector<int> myVector;
```

### Adding Elements

To add elements to the vector, use the `push_back()` member function:

```cpp
myVector.push_back(42);
myVector.push_back(99);
myVector.push_back(73);
```

### Accessing Elements

You can access the elements of the vector using the `[]` operator or the `at()` member function:

```cpp
int element = myVector[0];     // Access the first element using the [] operator
int elementAt = myVector.at(2); // Access the third element using the at() function
```

### Iterating Over Elements

You can use iterators to traverse the elements of the vector:

```cpp
for (Vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
    std::cout << *it << " ";
}
```

Alternatively, you can use a range-based for loop with C++11 or above:

```cpp
for (const auto& element : myVector) {
    std::cout << element << " ";
}
```

### Size and Capacity

You can get the size (number of elements) and capacity (allocated memory) of the vector:

```cpp
std::size_t size = myVector.size();
std::size_t capacity = myVector.capacity();
```

### Clearing the Vector

To remove all elements from the vector, use the `clear()` member function:

```cpp
myVector.clear();
```

### Checking if the Vector is Empty

You can check if the vector is empty using the `empty()` member function:

```cpp
if (myVector.empty()) {
    std::cout << "Vector is empty." << std::endl;
}
```

## Important Notes

- The `Vector` template class automatically manages the memory allocation and deallocation for the elements.
- If the number of elements exceeds the current capacity, the vector will automatically resize to accommodate more elements.
- The vector grows dynamically as more elements are added, making it flexible and efficient.

## Example

Here's a complete example demonstrating the usage of the `Vector` template class:

```cpp
#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> myVector;

    myVector.push_back(42);
    myVector.push_back(99);
    myVector.push_back(73);

    std::cout << "Vector elements: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Output:
```
Vector elements: 42 99 73
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Feel free to use and modify the `Vector` template class as per your requirements.

---
You can customize this README.md file to provide additional information or usage examples based on the specific features and modifications you have made to the `Vector` template class.
