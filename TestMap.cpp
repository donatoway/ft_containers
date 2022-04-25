#include "map/map.hpp"


#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YEL "\e[0;33m"


void testConstructor()
{
    std::cout << GREEN << "TEST CONSTRUCTORS\n";
    ft::map<char, int> map1;

    ft::pair<char, int> pair;
    char c = 'a';
    for (size_t i = 0; i < 5; i++)
    {
        pair = ft::make_pair(c++,i);
        map1.insert(pair);
    }
    ft::map<char, int> map2(map1);
    ft::map<char, int> map3(map2.begin(), map2.end());
     ft::map<char, int> map4 = map3;

    //--------- PRINTING ... --------------
    std::cout << "MAP1 DEFAULT:\n";
    ft::map<char, int>::iterator it;
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

void testIterator()
{
    ft::map<std::string, int> map1;

    map1["alberto"] = 0;
    map1["carlo"] = 1;
    map1["paolo"] = 2;
    const ft::map<std::string, int> map2(map1);
    ft::map<std::string, int>::iterator it;
    ft::map<std::string, int>::Reverse_iterator rev;
    ft::map<std::string, int>::Map_iterator_const const_it;
    ft::map<std::string, int>::Const_Rev_Map_Iterator constRev_it;

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


void testCapacity()
{
    ft::map<int, int> map1;
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

void testEementAccess()
{
    std::cout <<  GREEN <<"TEST ELEMENT ACCESS\n";
    ft::map<int, std::string> map1;
    
    map1[0] = "primo";
    map1[1] = "secondo";
    map1[2] = "terzo";
    map1[2] = "RimpiazzoTerzo";
    std::cout << map1[0] << "\n";
    std::cout << map1[1]<< "\n";
    std::cout << map1[2] << "\n";
}

void testModifiers()
{
    ft::map<int, int> map1;
    ft::map<int, int> map2;
    ft::map<int, int>::iterator it;
    ft::pair<int,int> pair;
    
    std::cout <<GREEN<< "TEST MODIFIERS\n";
    std::cout << "test insert whit a pair value\n";
    for (size_t i = 0; i < 10; i++)
    {
        pair = ft::make_pair(i, i); 
        map1.insert(pair);
    }
    for (it = map1.begin(); it != map1.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";
    
    map2.insert(map1.begin(), map1.end());
    std::cout << "test insert whit a range \n";

     for (it = map2.begin(); it != map2.end(); it++)
         std::cout << "first : " << it->first << " second : " << it->second << "\n";

    std::cout << "test insert whit a pair_val and it \n";
    pair = ft::make_pair(55, 10);
    map2.insert(map2.begin(), pair);
    std::cout <<  "first : " << map2.find(55)->first << " second "<< map2.find(55)->second<< "\n";
}


int main()
{
   // testConstructor();
  //  testIterator();
  //  testCapacity();
 //   testEementAccess();
    testModifiers();
}