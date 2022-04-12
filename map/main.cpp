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

  a[2] = 66;
  
  ft::map<int,int>::iterator it;

  for (it = a.begin(); it != a.end(); it++)
  {
    std::cout << "first :" <<  it->first << " " << "second: " <<it->second << "\n"; 
  }
  


   //AGGIUSTARE il red black tree in modo da allocare la memoria e distruggerla li dentro
 
}