#include <iostream>
#include "stack.h"

#define INITIAL_STACK_SIZE 2
#define STACK_GROWTH_RATE 2

using namespace std;

Stack::Stack(){
    top_index = 0;
    size = INITIAL_STACK_SIZE;
    elements = (int*) malloc(size * sizeof(int));
    checkAllocation();
    cout << "Stack Created, memory allocated" << endl;
}

Stack::~Stack(){
    top_index = -1;
    free(elements);
    cout << "Stack destroyed, memory freed" << endl;
}

void Stack::push(int element) {
    if (top_index >= size){
        size *= STACK_GROWTH_RATE;
        elements = (int*) realloc(elements, size * sizeof(int));
        checkAllocation();
    }
    elements[top_index++] = element;
    cout << "Element " << element << " pushed to stack" << endl;
}

int Stack::pop() {
    if (!isEmpty()) {
        top_index--;
        int element = elements[top_index];
        return element;
    }
    else {
        cout << "Stack is empty" << endl;
        abort();
    }
}

bool Stack::isEmpty() {
    if (size == 0)
        return true;
    else if (size > 0)
        return false;
    else {
        cout << "Stack doesnt exist anymore" << endl;
        abort();
    }
}

void Stack::checkAllocation() {
    if (!elements) {
        cout << "Memory allocation error" << endl;
        abort();
    }
}

