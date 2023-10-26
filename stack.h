#pragma once

class Stack
{

    int top_index;
    int size;
    int *elements;

public:
    Stack();
    ~Stack();
    Stack(const Stack &s);
    Stack operator+(const Stack &other);
    Stack& operator=(const Stack &other);
    void push(int element);
    int pop();
    bool isEmpty();
    void printSize();

private:
    void checkAllocation();
};
