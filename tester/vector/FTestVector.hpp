#ifndef FTESTVECTOR_HPP
#define FTESTVECTOR_HPP

#include "../../vector/vector.hpp"

void testVectConstructors()
{
    ft::vector<int>::iterator it;

    int arr[] = {1, 2, 3};
    std::cout << "TEST VECTOR\n";
    //default
    std::cout << "default\n";
    ft::vector<int> marco;
	marco.insert(marco.begin(), arr, arr + 3);
     for (it = marco.begin(); it != marco.end(); it++)
        std::cout << *it << "\n";
    std::cout << "fill\n";
    //fill  crea 5 element di valore 5
    ft::vector<int> jon(5, 10);
    for (it = jon.begin(); it != jon.end(); it++)
        std::cout << *it << "\n";
    //range
     std::cout << "range\n";
    ft::vector<int> carl(marco.begin(), marco.end());
    for (it = carl.begin(); it != carl.end(); it++)
        std::cout << *it << "\n";
    
    //copy
     std::cout << "copy constructor\n";
     ft::vector<int> mik(jon);
     ft::vector<int> pio = mik;
    for (it = mik.begin(); it != mik.end(); it++)
        std::cout << *it << "\n";

    std::cout << "assign constructor\n";
     for (it = pio.begin(); it != pio.end(); it++)
        std::cout << *it << "\n";
    
    //RANGE

}

void testIterator()
{
     std::cout << "TEST ITERATOR\n";
    ft::vector<char>  vect;
    ft::vector<char>::iterator it;
    ft::vector<char>::reverse_iterator rev;
    ft::vector<char>::const_iterator const_it;

     char c = 'a';
    while (c < 'e')
        vect.push_back(c++);

    const ft::vector<char>  vect2 = vect;
    std::cout << "test iterator\n";
    for (it = vect.begin(); it != vect.end(); it++)
        std::cout << *it <<"\n";
    std::cout << "test reverse iterator\n";
     for (rev = vect.rbegin(); rev != vect.rend(); rev++)
        std::cout << *rev <<"\n";
    std::cout << "test const iterator\n";
     for (const_it = vect.begin(); const_it != vect.end(); const_it++)
        std::cout << *const_it <<"\n";
}






#endif