#ifndef FT_STACK_TEST
#define FT_STACK_TEST

#include "../../stack/stack.hpp"

void test_constructor()
{
    ft::stack<char> c;
    ft::stack<char> tmp;

    for (char i = 'e'; i >= 'a'; i--)
        c.push(i);
    tmp = c;
    std::cout <<GREEN<< "test copy constructor\n";
   ft::stack<char> _copy(c);
   while (!_copy.empty())
   {
       std::cout << _copy.top() << " ";
       _copy.pop();
   }

   std::cout << "\ntest assign\n";
   ft::stack<char> assign = tmp;
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

void test_modifiers()
{
    std::cout << GREEN<<"TEST MODIFIERS\ntest push and pop\n";
    ft::stack<int, ft::vector<int> > stack;
    for (size_t i = 0; i < 5; i++)
        stack.push(i);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "\n";
}

void comaparison()
{
    std::cout << GREEN<< "TEST COMPARISON\n";

    ft::stack<int>  stack;
    ft::stack<int>  stack2;

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

void ft_stack_tester()
{
    test_modifiers();
    test_constructor();
    comaparison();
}

#endif