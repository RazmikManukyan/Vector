#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    v1.remove(1, 2);

    v1.print();
}
