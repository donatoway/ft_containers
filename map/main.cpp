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


/*
  ft::pair<int, int> a; //value_type
  a = ft::make_pair(10, 9); // first, second
  ft::Node<ft::pair<int, int> > *node = new ft::Node<ft::pair<int, int> >(a);
  ft::pair<int, int> *it;
  it = &node->data; //it = begin();
  std::cout << it->first << "\n";
*/

  ft::map<int, int> map2;


  for (size_t i = 0; i < 10; i++)
  {
    ft::pair<int, int> pair;
    pair = ft::make_pair(i, i);
    map2.insert(pair);

  }
  ft::Map_iterator<ft::pair<int, int> > it;

  for (it = map2.begin(); it != map2.end(); it++)
  {
    std::cout << it->first<< "\n";
  }

  //iterator completo
  //continuare con le altre funzioni di map 
 


}