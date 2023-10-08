#include <iostream>
#include "stack.h"

#define INITIAL_STACK_SIZE 2

using namespace std;

Stack::Stack(){
    top_index = 0;
    size = INITIAL_STACK_SIZE;
    elements = (int*) malloc(size * sizeof(int));
}

int Stack::push(int element) {
    return element;
}

int Stack::pop() {
    return;
}

int Stack::isEmpty() {
    return;
}
