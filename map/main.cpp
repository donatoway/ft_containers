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

//#include "Tree_iterator.hpp"


int main()
{

  ft::map<int, int> a;

  for (size_t i = 0; i < 10; i++)
  {
    ft::pair<int, int> pai;
    pai = ft::make_pair(i,i);
    a.insert(pai);
  }
  
  
  ft::map<int,int>::iterator it;


  it = a.find(3);
   std::cout << it->first << "\n"; 

   //implementare search
 
}