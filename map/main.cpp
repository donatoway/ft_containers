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
   // ft::map<int, int>::iterator it2;


  
    it = map1.begin();
    map1.erase(it, map1.end());

  map1._tree.printInOrder();
      

      //concentrarsi sull último elemento, passare a iterator l'ultimo elemento, l elemento e il compare
      //guarde llefranc che piu chiaro
  return 0;
}