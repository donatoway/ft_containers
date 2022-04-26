#ifndef FTESTVECTOR_HPP
#define FTESTVECTOR_HPP

#include "../../vector/vector.hpp"
#include <iostream>
#include <vector>
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

void testCapacity()
{
    ft::vector<int> vect;
   for (size_t i = 0; i < 1000; i++)
    vect.push_back(i);
    std::cout << "TEST CAPACITY\ntest size: \n";
    std::cout << vect.size() << "\n";
    std::cout << "test max_size\n";
    std::cout << vect.max_size() << "\n";
    std::cout << "test capacity\n";
    std::cout << vect.capacity() << "\n";
    std::cout << "test empty: return 0 if not\n";
    std::cout << vect.empty() << "\n";
    std::cout << "test resize\n";
    vect.resize(5);
    std::cout << vect.size() << "\n";
    std::cout << vect.capacity() << "\n";
    std::cout << "test reserve\n";
    vect.reserve(100);
    std::cout << vect.size() << "\n";
    std::cout << vect.capacity() << "\n";
    
}

void    elementAccess()
{
    std::cout << "TEST ELEMENT ACCESS \n";
    ft::vector<int> myvector (10);   // 10 zero-initialized elements

    ft::vector<int>::size_type sz = myvector.size();

    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    std::cout << "test at:\n";
    std::cout << "pos 0: " <<  myvector.at(0) << "\n";
    std::cout << "pos 9: " <<  myvector.at(9) << "\n";
     std::cout << "pos 5: " <<  myvector.at(5) << "\n";
     std::cout << "front : " <<  myvector.front() << "\n";
     std::cout << "back : " <<  myvector.back() << "\n";
}

void    testModifiers()
{
    std::cout << "TEST MODIFIERS\n";
    ft::vector<std::string>             vect;
    ft::vector<std::string>::iterator   it;

    vect.push_back("marco");
    vect.push_back("giovanni");
    vect.push_back("sara");
    vect.push_back("carlo");
    vect.push_back("gimmy");

    std::cout << "\ntest push back\n";
    for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << "\ntest pop back\n";
    vect.pop_back();
    vect.pop_back();
    for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << "\ntest insert\n";
    vect.insert(vect.begin(), "luigi");
    vect.insert(vect.end(), "giuseppe");
    vect.insert(--it, 2, "gianni");
    for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << "\ninsert range to position begin, element from begin to it\n";
    vect.insert(vect.begin(),vect.begin(), vect.end());
    for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << "\ntest erase :\n";
    vect.erase(vect.begin());
    vect.erase(vect.end());
    for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
     std::cout << "\ntest erase whit range: from gianni to giovanni\n";
     it = vect.begin();
     it++;
     vect.erase(it, --vect.end());
     for ( it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << "\ntest clear\n";
    vect.clear();
    if (vect.size() == 0)
        std::cout << "vector is empty\n";
    for (it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    ft::vector<std::string> vect2(5, "element");
    vect.swap(vect2);
    std::cout << "test swap\nvector :";
    for (it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    if (vect2.size() == 0)
        std::cout << "\nvector2 is empty\n";
    for (it = vect2.begin(); it != vect2.end(); it++)
        std::cout << *it << " ";
     std::cout << "\ntest assign\nvect2 : ";
    vect2 = ft::vector<std::string>(6, "assign");
    for (it = vect2.begin(); it != vect2.end(); it++)
        std::cout << *it << " ";
}

#endif