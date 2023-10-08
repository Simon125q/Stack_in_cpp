class Stack {

    private:
    
    int top_index;
    int size;
    int *elements;

    public:
    Stack();
    int push(int element);
    int pop();
    int isEmpty();
};
