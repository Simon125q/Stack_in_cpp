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

Stack::Stack(Stack &s) {
    top_index = s.top_index;
    size = s.size;
    elements = (int*) malloc(size * sizeof(int));
    checkAllocation();
    for (int index = 0; index < top_index; index++) {
        elements[index] = s.elements[index];
    }
    cout << "Stack created based on other stack, memory allocated" << endl;
}

Stack Stack::operator+(const Stack& other) const {
    Stack new_stack;
    new_stack.top_index = top_index + other.top_index;
    new_stack.size = size + other.size;
    new_stack.elements = (int*) malloc(new_stack.size * sizeof(int));
    new_stack.checkAllocation();
    for(int index = 0; index < top_index; index++) {
        new_stack.elements[index] = elements[index];
    }
    for(int index = top_index; index < top_index + other.top_index; index++) {
        new_stack.elements[index] = other.elements[index - top_index];
    }

    return new_stack;
}

void Stack::operator=(Stack& other) {
    top_index = other.top_index;
    size = other.size;
    free(elements);
    elements = (int*) malloc(size * sizeof(int));
    for (int index = 0; index < top_index; index++) {
        elements[index] = other.elements[index];
    }
}

void Stack::push(int element) {
    if (top_index >= size){
        size *= STACK_GROWTH_RATE;
        elements = (int*) realloc(elements, size * sizeof(int));
        checkAllocation();
        cout << "Memory reallocated" << endl;
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
        free(elements);
        abort();
    }
}

bool Stack::isEmpty() {
    if (top_index == 0)
        return true;
    else if (top_index > 0)
        return false;
    else {
        cout << "Stack doesnt exist anymore" << endl;
        free(elements);
        abort();
    }
}

void Stack::checkAllocation() {
    if (!elements) {
        cout << "Memory allocation error" << endl;
        free(elements);
        abort();
    }
}

