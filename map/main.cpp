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
    ft::map<int, int>::iterator it2;

  it = map1.begin();
 



for (it =map1.begin(); it != map1.end(); it++)
{
  map1.erase(it);
}


for (it =map1.begin(); it != map1.end(); it++)
{
 std::cout << it->first << "\n";
}

  map1._tree.printInOrder();
      

      //ci deve essere qualcosa che non va nell'iterator
      //vedere cosa e che non va o rifarlo se si fa prima
  return 0;
}