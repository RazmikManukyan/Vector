#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> v1;
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    //v1.print();
    for(Vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
        std::cout << *it;
    }
}
