class Stack {
    
    int top_index;
    int size;
    int *elements;

    public:
    Stack();
    ~Stack();
    void push(int element);
    int pop();
    bool isEmpty();

    private:
    void checkAllocation();
};
