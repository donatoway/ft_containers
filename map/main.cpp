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
  it++;
  it++;
it++;
  map1.erase(map1.begin(),map1.end());
  
  for (it2 = map1.begin(); it2 != map1.end(); it2++)
  {
    std::cout << it2->first << "\n";
  }
  
    //DELETE COMPLETATO continuare a finire gli insert e le altre funzioni
      
  return 0;
}