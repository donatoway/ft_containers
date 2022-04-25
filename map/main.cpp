#include <iostream>
#include <queue>
#include <algorithm>
#include "pair.hpp"
#include "map.hpp"
#include <map>
 #include <cstdlib>
#include <string>
#include <iomanip>
#include "map_iterator.hpp"


int main()
{

  ft::map<int,int> map1;
 

  ft::pair<int, int> pai;
  for (size_t i = 0; i < 10; i++)
  {
      pai = ft::make_pair(i, i);
    map1.insert(pai);
  }


  ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator >  a;

  a = map1.equal_range(9);
  
   std::cout << a.first->first << "\n";
  std::cout << a.second->first << "\n";

  //CREARE UN FILE BINARIO CHE TESTA STD E FT MAP
  return 0;
}