#include <iostream>
#include "stack.h"

#define INITIAL_STACK_SIZE 2
#define STACK_GROWTH_RATE 2
#define ERROR 1

using namespace std;

Stack::Stack()
{
    top_index = 0;
    size = INITIAL_STACK_SIZE;
    elements = (int *)malloc(size * sizeof(int));
    checkAllocation();
    cout << "Stack Created, memory allocated" << endl;
}

Stack::~Stack()
{
    top_index = -1;
    free(elements);
    cout << "Stack destroyed, memory freed" << endl;
}

Stack::Stack(const Stack &s)
{
    top_index = s.top_index;
    size = s.size;
    elements = (int *)malloc(size * sizeof(int));
    checkAllocation();
    for (int index = 0; index < top_index; index++)
    {
        elements[index] = s.elements[index];
    }
    cout << "Stack created based on other stack, memory allocated" << endl;
}

Stack Stack::operator+(const Stack &other)
{
    Stack new_stack;
    new_stack.top_index = top_index + other.top_index;
    new_stack.size = size + other.size;
    new_stack.elements = (int *)malloc(new_stack.size * sizeof(int));
    new_stack.checkAllocation();
    for (int index = 0; index < top_index; index++)
    {
        new_stack.elements[index] = elements[index];
    }
    for (int index = top_index; index < top_index + other.top_index; index++)
    {
        new_stack.elements[index] = other.elements[index - top_index];
    }
    cout << "Stacks added to each other" << endl;
    return new_stack;
}

Stack& Stack::operator=(const Stack &other)
{
    if (other.top_index + 1 > size)
    {
        size = other.size;
        elements = (int *)realloc(elements, size * sizeof(int));
        checkAllocation();
        cout << "Memory reallocated in assigment" << endl;
    }
    top_index = other.top_index;
    for (int index = 0; index < top_index; index++)
    {
        elements[index] = other.elements[index];
    }
    cout << "Stack assigned" << endl;

    return *this;
}

void Stack::push(int element)
{
    if (top_index >= size)
    {
        size *= STACK_GROWTH_RATE;
        elements = (int *)realloc(elements, size * sizeof(int));
        checkAllocation();
        cout << "Memory reallocated" << endl;
    }
    elements[top_index++] = element;
    cout << "Element " << element << " pushed to stack" << endl;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        top_index--;
        int element = elements[top_index];
        cout << "Element " << element << " poped" << endl;
        return element;
    }
    else
    {
        cout << "Stack is empty" << endl;
        free(elements);
        exit(ERROR);
    }
}

bool Stack::isEmpty()
{
    if (top_index == 0)
        return true;
    else if (top_index > 0)
        return false;
    else
    {
        cout << "Stack doesnt exist anymore" << endl;
        free(elements);
        exit(ERROR);
    }
}

void Stack::checkAllocation()
{
    if (!elements)
    {
        cout << "Memory allocation error" << endl;
        free(elements);
        exit(ERROR);
    }
}

void Stack::printSize()
{
    cout << "Stack size is " << top_index << endl;
}