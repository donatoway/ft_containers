#ifndef STDTESTVECTOR_HPP
#define STDTESTVECTOR_HPP

#include <iostream>
#include <vector>
#define YELLOW  "\033[33m"      /* Yellow */

void testVectConstructors2()
{
    std::vector<int>::iterator it;

    int arr[] = {1, 2, 3};
    std::cout <<YELLOW<< "TEST VECTOR\n";
    //default
    std::cout << "default\n";
    std::vector<int> marco;
	marco.insert(marco.begin(), arr, arr + 3);
     for (it = marco.begin(); it != marco.end(); it++)
        std::cout << *it << "\n";
    std::cout << "fill\n";
    //fill  crea 5 element di valore 5
    std::vector<int> jon(5, 10);
    for (it = jon.begin(); it != jon.end(); it++)
        std::cout << *it << "\n";
    //range
     std::cout << "range\n";
    std::vector<int> carl(marco.begin(), marco.end());
    for (it = carl.begin(); it != carl.end(); it++)
        std::cout << *it << "\n";
    
    //copy
     std::cout << "copy constructor\n";
     std::vector<int> mik(jon);
     std::vector<int> pio = mik;
    for (it = mik.begin(); it != mik.end(); it++)
        std::cout << *it << "\n";

    std::cout << "assign constructor\n";
     for (it = pio.begin(); it != pio.end(); it++)
        std::cout << *it << "\n";
    
    //RANGE

}

void testIterator2()
{
     std::cout <<YELLOW<< "TEST ITERATOR\n";
    std::vector<char>  vect;
    std::vector<char>::iterator it;
    std::vector<char>::reverse_iterator rev;
    std::vector<char>::const_iterator const_it;

     char c = 'a';
    while (c < 'e')
        vect.push_back(c++);

    const std::vector<char>  vect2 = vect;
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

void testCapacity2()
{
    std::vector<int> vect;
   for (size_t i = 0; i < 1000; i++)
    vect.push_back(i);
    std::cout <<YELLOW<< "TEST CAPACITY\ntest size: \n";
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

void    elementAccess2()
{
    std::cout << YELLOW<<"TEST ELEMENT ACCESS \n";
    std::vector<int> myvector (10);   // 10 zero-initialized elements

    std::vector<int>::size_type sz = myvector.size();

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

    std::cout <<YELLOW<< "myvector contains:";
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

void    testModifiers2()
{
    std::cout << YELLOW<<"TEST MODIFIERS\n";
    std::vector<std::string>             vect;
    std::vector<std::string>::iterator   it;

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
    std::vector<std::string> vect2(5, "element");
    vect.swap(vect2);
    std::cout << "test swap\nvector :";
    for (it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    if (vect2.size() == 0)
        std::cout << "\nvector2 is empty\n";
    for (it = vect2.begin(); it != vect2.end(); it++)
        std::cout << *it << " ";
     std::cout << "\ntest assign\nvect2 : ";
    vect2 = std::vector<std::string>(6, "assign");
    for (it = vect2.begin(); it != vect2.end(); it++)
        std::cout << *it << " ";
        
}

void testOperators2()
{
    std::cout << YELLOW<<"\nTEST OPERATORS\n";
    std::vector<int> vect(5, 10);
    std::vector<int> vect2(2, 7);
    if (vect == vect2)
        std::cout << "vect is equal vect2\n";
    else if (vect != vect2)
        std::cout << "vect is not  equal vect2\n";

    if (vect > vect2)
         std::cout << "vect is greater than vect2\n";
    if (vect2 < vect)
        std::cout << "vect2 is less vect\n";
    if (vect >= vect2)
         std::cout << "vect is greater-equal than vect2\n";
    if (vect2 <= vect)
        std::cout << "vect2 is less-equal than vect\n";
}

void test_std_vector()
{
    testVectConstructors2();
    std::cout << "\n\n-----------------------\n\n";
    testIterator2();
    std::cout << "\n\n-----------------------\n\n";
    testCapacity2();
    std::cout << "\n\n-----------------------\n\n";
    elementAccess2();
    std::cout << "\n\n-----------------------\n\n";
    testModifiers2();
    std::cout << "\n\n-----------------------\n\n";
    testOperators2();
}
#endif