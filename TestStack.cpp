#include <iostream>
#include "stack.h"

using namespace std;

void test1(int num_of_tested_elem);
void test2(int num_of_tested_elem);
void test3(int num_of_tested_elem);

int main() {
    
    test1(19);
    test2(21);
    test3(10);

    return 0;
}

void test1(int num_of_tested_elem) {
    printf("TEST 1\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++) {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++) {
        cout << "Poped element: " << s.pop() << endl;
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
}

void test2(int num_of_tested_elem) {
    printf("TEST 2\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++) {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
    
}

void test3(int num_of_tested_elem) {
    printf("TEST 3\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++) {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem + 1; num++) {
        cout << "Poped element: " << s.pop() << endl;
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
}
