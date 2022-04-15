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

    ft::map<int,int>  map1;

    for (int i = 0; i < 10; i++)
    {
       ft::pair<int, int>      pai;
        pai = ft::make_pair(i, i);

        map1.insert(pai);
    }

    ft::map<int, int>::iterator it;

    for (it = map1.begin(); it != map1.end(); it++)
    {
      std::cout << it->first << "\n";
    }
    
    

    // COMPLETARE INSERT GLI ALTRI 2 COSTRUTTORI, DOPO STUDIARE DELETE IN TREE ED INIZIARE
    // AD IMPLEMENTARLO
  return 0;
}