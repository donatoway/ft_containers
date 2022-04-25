#ifndef STDTESTMAP_HPP
#define STDTESTMAP_HPP

#include <iostream>
#include <map>


#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YEL "\e[0;33m"


void testConstructor1()
{
    std::cout << GREEN << "TEST CONSTRUCTORS\n";
    std::map<char, int> map1;

    std::pair<char, int> pair;
    char c = 'a';
    for (size_t i = 0; i < 5; i++)
    {
        pair = std::make_pair(c++,i);
        map1.insert(pair);
    }
    std::map<char, int> map2(map1);
    std::map<char, int> map3(map2.begin(), map2.end());
     std::map<char, int> map4 = map3;

    //--------- PRINTING ... --------------
    std::cout << "MAP1 DEFAULT:\n";
    std::map<char, int>::iterator it;
    for (it = map1.begin(); it != map1.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << "\n";
    std::cout << std::endl << "MAP2 COPYCONSTRUCTOR\n";
     for (it = map2.begin(); it != map2.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << "\n";
    std::cout << std::endl << "MAP3 RANGE ITERATOR\n";
     for (it = map3.begin(); it != map3.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << "\n";
     std::cout << std::endl << "MAP4 ASSIGN\n";
     for (it = map4.begin(); it != map4.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << "\n";

};

void testIterator1()
{
    std::map<std::string, int> map1;

    map1["alberto"] = 0;
    map1["carlo"] = 1;
    map1["paolo"] = 2;
    const std::map<std::string, int> map2(map1);
    std::map<std::string, int>::iterator it;
    std::map<std::string, int>::reverse_iterator rev;
    std::map<std::string, int>::const_iterator const_it;
    std::map<std::string, int>::const_reverse_iterator constRev_it;

    std::cout << GREEN"TEST ITERATOR\n\nTest iterator\n";
    for (it = map1.begin(); it != map1.end(); it++)
        std::cout << "first : " << it->first << " second : " << it->second << "\n";

    std::cout << "\ntest reverse iterator\n";
    for (rev = map1.rbegin(); rev != map1.rend(); rev++)
        std::cout << "first : " << rev->first << " second : " << rev->second << "\n";

    std::cout << "\ntest reverse iterator\n";
    for (rev = map1.rbegin(); rev != map1.rend(); rev++)
        std::cout << "first : " << rev->first << " second : " << rev->second << "\n";

    std::cout << "\ntest const iterator\n";
    for (const_it = map2.begin(); const_it != map2.end(); const_it++)
        std::cout << "first : " << const_it->first << " second : " << const_it->second << "\n";
    
    std::cout << "\ntest const reverse iterator\n";
    for (constRev_it = map2.rbegin(); constRev_it != map2.rend(); constRev_it++)
        std::cout << "first : " << constRev_it->first << " second : " << constRev_it->second << "\n";
     
}


void testCapacity1()
{
    std::map<int, int> map1;
    int i = 0;
    while (i++ < 1000)
        map1[i] = i;

    std::cout << GREEN"TEST CAPACITY : \ntest size()\n";

    std::cout << map1.size() << "\n";

    std::cout << "TEST max_size()\n";
    std::cout << map1.max_size() << "\n";

    map1.erase(2);
     std::cout << "test size after delete 1 element\n";
    std::cout << map1.size() << "\n";

      std::cout << "test empty\n";
    if (map1.empty() == 0)
        std::cout << "Container is not empty\n";
}

void testEementAccess1()
{
    std::cout <<  GREEN <<"TEST ELEMENT ACCESS\n";
    std::map<int, std::string> map1;
    
    map1[0] = "primo";
    map1[1] = "secondo";
    map1[2] = "terzo";
    map1[2] = "RimpiazzoTerzo";
    std::cout << map1[0] << "\n";
    std::cout << map1[1]<< "\n";
    std::cout << map1[2] << "\n";
}

void testModifiers1()
{
    std::map<int, int> map1;
    std::map<int, int> map2;
    std::map<int, int>::iterator it;
    std::pair<int,int> pair;
    
    std::cout <<GREEN<< "TEST MODIFIERS\n";
    std::cout << "test insert whit a pair value\n";
    for (size_t i = 0; i < 10; i++)
    {
        pair = std::make_pair(i, i); 
        map1.insert(pair);
    }
    for (it = map1.begin(); it != map1.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";
    
    map2.insert(map1.begin(), map1.end());
    std::cout << "test insert whit a range \n";

     for (it = map2.begin(); it != map2.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";

    std::cout << "test insert whit a pair_val and it \n";
    pair = std::make_pair(55, 10);
    map2.insert(map2.begin(), pair);
    std::cout <<  "first : " << map2.find(55)->first << " second "<< map2.find(55)->second<< "\n";

    std::cout << "test erase whit a key\n";
    std::cout << "remove 2\n";
    map1.erase(2);
    for (it = map1.begin(); it != map1.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";
     std::cout << "test erase range iterator\n";
     std::cout << "removes elements from 5 to 9\n";
    map1.erase(map1.find(5), map1.end());
    for (it = map1.begin(); it != map1.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";

    std::cout << "test clear\n";
    map1.clear();
    if (map1.empty())
        std::cout << "map container is empty\n";
    std::cout << "test swap\nmap1 now is map2\n";
    map1.swap(map2);
    for (it = map1.begin(); it != map1.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";

}

void    testObserves21()
{
     std::cout << "\nTEST VALUE_COMPARE\n";
    std::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    std::pair<char,int> highest = *mymap.rbegin();          // last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest) );
}

void    testObserves1()
{
    std::cout << GREEN<<"TEST KEY_COMP\n";
    std::map<char,int> mymap;

    std::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    char highest = mymap.rbegin()->first;     // key value of last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );
    testObserves21();
}

void    testOperation1()
{
    std::map<char,int> mymap;

    mymap['a'] = 1;
    mymap['b'] = 2;
    mymap['c'] = 3;
    mymap['d'] = 3;
    mymap['e'] = 3;

    std::cout <<GREEN << "TEST OPERATION\ntest find\n";

    std::cout << "if map have an 'a' elemnt print it:\n";
    if ( mymap.find('a')->first)
        std::cout << mymap.find('a')->first << "\n";
    std::cout << "test count\n";
    std::cout << "if map have an 'c' elemnt print it:\n";
    if (mymap.count('c'))
        std::cout << "element c found\n";

    std::cout << "test lower_bound and upper_bound\n";

    std::map<char, int>::iterator it;

    for (it = mymap.lower_bound('b'); it != mymap.upper_bound('d'); it++)
        std::cout << it->first << "\n";

    std::cout << "test equal_range\n";
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower value in the range is : " << ret.first->first << "\n";
    std::cout << "high value in the range is : " << ret.second->first << "\n";

}

void std_test_map()
{
      testConstructor1();
    std::cout << "\n\n-----------------------\n\n";
    testIterator1();
    std::cout << "\n\n-----------------------\n\n";
    testCapacity1();
    std::cout << "\n\n-----------------------\n\n";
    testEementAccess1();
    std::cout << "\n\n-----------------------\n\n";
    testModifiers1();
    std::cout << "\n\n-----------------------\n\n";
    testObserves1();
    std::cout << "\n\n-----------------------\n\n";
    testOperation1();

}

#endif