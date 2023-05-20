#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H
#include "Vector.h"


class Stack : private Vector {
public:
    void push(int);
    int top();
    void pop();
};

#endif //VECTOR_STACK_H
