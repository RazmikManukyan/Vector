#include "Stack.h"

void Stack::push(int num) {
    this->push_back(num);
}

int Stack::top() {
    return this->back();
}

void Stack::pop() {
    this->pop_back();
}