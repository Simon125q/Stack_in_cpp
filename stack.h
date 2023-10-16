#pragma once

class Stack
{

    int top_index;
    int size;
    int *elements;

public:
    Stack();
    ~Stack();
    Stack(Stack &s);
    Stack operator+(const Stack &other);
    void operator=(Stack &other);
    void push(int element);
    int pop();
    bool isEmpty();
    void printSize();

private:
    void checkAllocation();
};
