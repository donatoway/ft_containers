#ifndef STD_STACK_TESTER
#define STD_STACK_TESTER

#include <iostream>
#include <stack>
#include <vector>

void test_constructor1()
{
    std::stack<char> c;
    std::stack<char> tmp;

    for (char i = 'e'; i >= 'a'; i--)
        c.push(i);
    tmp = c;
    std::cout <<YELLOW<< "test copy constructor\n";
   std::stack<char> _copy(c);
   while (!_copy.empty())
   {
       std::cout << _copy.top() << " ";
       _copy.pop();
   }

   std::cout << "\ntest assign\n";
   std::stack<char> assign = tmp;
   while (!assign.empty())
   {
       std::cout << assign.top() << " ";
       assign.pop();
   }

    std::cout << "test size\nsieze of tmp : ";
    std::cout << tmp.size() << "\n";
    if (!tmp.empty())
        std::cout << "tmp is not empty\n";
    if (assign.empty())
        std::cout << "assign is  empty\n";
}

void test_modifiers1()
{
    std::cout << YELLOW<<"TEST MODIFIERS\ntest push and pop\n";
    std::stack<int, std::vector<int> > stack;
    for (size_t i = 0; i < 5; i++)
        stack.push(i);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "\n";
}

void comaparison1()
{
    std::cout << YELLOW<< "TEST COMPARISON\n";

    std::stack<int>  stack;
    std::stack<int>  stack2;

    int i = 0;
    while (i++ < 5)
        stack.push(i);
    while (i++ < 6)
        stack2.push(i);
    
    if (stack == stack2)
        std::cout << "stack is equal stack2\n";
    if (stack != stack2)
        std::cout << "stack is not equal stack2\n";
    if (stack < stack2)
        std::cout << "stack is less than stack2\n";
    if (stack > stack2)
        std::cout << "stack is greater than stack2\n"; 
    if (stack >= stack2)
        std::cout << "stack is greater-equal than stack2\n";
    if (stack <= stack2)
        std::cout << "stack is less-equal than stack2\n"; 
}

void std_stack_tester()
{
    test_modifiers1();
    test_constructor1();
    comaparison1();
}
#endif