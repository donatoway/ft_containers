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
    ft::pair<int, int> i;
    i = ft::make_pair(10,9);
    ft::map<int,int> mymap;

    ft::map<int, int>::iterator it;

    for (int i = 0; i < 10; i++)
    {
         ft::pair<int, int> pp;
        pp = ft::make_pair(i,i);
        mymap.insert(pp);
    }
     ft::map<int,int>  mymap2 =mymap;

    for (it = mymap2.begin(); it != mymap2.end(); it++)
    {
        std::cout << it->first << "\n";
    }


    // COMPLETARE INSERT GLI ALTRI 2 COSTRUTTORI, DOPO STUDIARE DELETE IN TREE ED INIZIARE
    // AD IMPLEMENTARLO
  return 0;
}