#include <iostream>
#include <queue>
#include <algorithm>
#include "pair.hpp"
#include "map.hpp"
#include <map>
 #include <cstdlib>
#include <string>
#include <iomanip>
#include "Tree_iterator.hpp"


int main()
{

  ft::map<int,int> map1;
 

  ft::pair<int, int> pai;
  for (size_t i = 0; i < 10; i++)
  {
      pai = ft::make_pair(i, i);
    map1.insert(pai);
  }
  const ft::map<int,int> map2(map1);
  ft::map<int, int>::Const_Rev_Map_Iterator it;

    for (it = map2.rbegin(); it != map2.rend(); it++)
    {
        std::cout << it->first << "\n";
    }


    //ITERATOR, INSERT, DELETE COMPLETATI!!!!!
    // FARE DA SOLO TUTTE LE RESTANTI FUNZIONI DAJE!!!!
  return 0;
}