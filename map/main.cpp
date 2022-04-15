#include <iostream>
#include <queue>
#include <algorithm>
 #include "RBtree.hpp"
#include "pair.hpp"
#include "map.hpp"
#include <map>
 #include <cstdlib>
#include <string>
#include <iomanip>
#include "Tree_iterator.hpp"



int main()
{
    ft::map<int, int> map1;
    ft::pair<int, int> pai;

    for (size_t i = 0; i < 10; i++)
    {
      pai = ft::make_pair(i, i);
      map1.insert(pai);
    }

    ft::map<int , int>::iterator it;

 

    map1.erase(6);
    map1.erase(7);
    map1.erase(8);
    map1.erase(9);
    map1.erase(5);
    
    for (it  = map1.begin(); it != map1.end(); it++)
    {
      std::cout << it->first << "\n";
    }
      //Risistemare ITERATOR
      //E CONTINUARE I DELETE
      
  return 0;
}