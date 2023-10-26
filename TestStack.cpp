#include <iostream>
#include "stack.h"

using namespace std;

void test1(int num_of_tested_elem);
void test2(int num_of_tested_elem);
void test3(int num_of_tested_elem);
//void test4(int num_of_tested_elem);
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void byValue(Stack s);
void byReference(Stack *s);

int main()
{

    test1(19);
    test2(21);
    test3(10);
    // test4(12);
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}

void test1(int num_of_tested_elem)
{
    printf("\nTEST 1\n\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s.pop();
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
}

void test2(int num_of_tested_elem)
{
    printf("\nTEST 2\n\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
}

void test3(int num_of_tested_elem)
{
    printf("\nTEST 3\n\n");
    Stack s1;

    cout << "Stack 1 empty: " << s1.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s1.push(num);
    }

    Stack s2(s1);

    cout << "Stack 1 empty: " << s1.isEmpty() << endl;
    cout << "Stack 2 empty: " << s2.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s2.push(num);
    }

    cout << "Stack 2 empty: " << s2.isEmpty() << endl;

    for (int num = 0; num < 2 * num_of_tested_elem; num++)
    {
        s2.pop();
    }

    cout << "Stack 1 empty: " << s1.isEmpty() << endl;
    cout << "Stack 2 empty: " << s2.isEmpty() << endl;
}

void test4(int num_of_tested_elem)
{
    printf("\nTEST 4\n\n");
    Stack s;

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem; num++)
    {
        s.push(num);
    }

    cout << "Stack empty: " << s.isEmpty() << endl;

    for (int num = 0; num < num_of_tested_elem + 1; num++)
    {
        s.pop();
    }

    cout << "Stack empty: " << s.isEmpty() << endl;
}

void test5()
{
    printf("\nTEST 5\n\n");

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);

    Stack s3 = s1;

    Stack s4;
    s4.push(10);
    s4 = s1;
    s4.pop();
    s4.pop();
}

void test6()
{
    printf("\nTEST 6\n\n");

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);

    s2 = s1;

    s2.pop();
    s2.pop();
    s1.pop();
    s1.pop();
}

void test7()
{
    printf("\nTEST 7\n\n");

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);

    s1.push(4);
    s1.push(5);
    s1.push(6);

    s2 = s1;

    s2.pop();
    s2.pop();
    s1.pop();
    s1.pop();
}

void test8()
{
    printf("\nTEST 8\n\n");

    Stack s1, s2;

    cout << "By value:" << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.printSize();
    byValue(s1);
    s1.printSize();
    s1.pop();

    cout << "By reference:" << endl;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.printSize();
    byReference(&s2);
    s2.printSize();
    s2.pop();
}

void test9()
{
    printf("\nTEST 9\n\n");

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2 = s1;

    s2.pop();
    s2.pop();
    s1.pop();
    s1.pop();
}

void test10()
{
    printf("\nTEST 10\n\n");

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);

    s2.push(4);
    s2.push(5);

    Stack s3(s2);

    s3.pop();

    s1 = s2 = s3;

    s2.pop();
    s2.pop();
    s1.pop();
    s1.pop();
}

void byValue(Stack s)
{
    while(!s.isEmpty())
    {
        s.pop();
    }
    s.push(100);
}

void byReference(Stack *s)
{
    while(!s->isEmpty())
    {
        s->pop();
    }
    s->push(100);
}
