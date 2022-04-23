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

    for (size_t i = 0; i < 5; i++)
    {
      pai = ft::make_pair(i, i);
      map1.insert(pai);
    }


    ft::map<int , int>::iterator it;
    ft::map<int, int>::iterator it2;

    it = map1.begin();
  //  it++;
    //std::cout << it->first << "\n";
    map1.erase(it,map1.end());
    
    for (it = map1.begin(); it != map1.end(); it++)
    {
      std::cout << it->first << "\n";
    }
    map1._tree.printInOrder();
    //DELETE COMPLETATO continuare a finire gli insert e le altre funzioni
      
  return 0;
}