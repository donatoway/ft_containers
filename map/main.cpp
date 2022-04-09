#include <iostream>
#include <queue>
#include <algorithm>
 #include "RBtree.hpp"
#include "pair.hpp"
#include "map.hpp"
#include <map>
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

  ft::map<int, int> map1;

  ft::pair<int, int> pair;
  pair = ft::make_pair(10, 9);

  ft::pair<int, int> pair2;
  pair2 = ft::make_pair(20, 21);

  ft::pair<int, int> pair3;
  pair3 = ft::make_pair(30, 39);

  ft::pair<int, int> pair4;
  pair4 = ft::make_pair(40, 41);

  map1.insert(pair);
  map1.insert(pair2);

   map1.insert(pair3);
  map1.insert(pair4);

  ft::map<int, int>::iterator it;


  it = map1.begin();
  std::cout << it->first << "\n";
  ++it;

  std::cout << it->first << "\n";

  ++it;

  std::cout << it->first << "\n";

  it--;

  std::cout << it->first << "\n";
  
  it--;

  std::cout << it->first << "\n";

/*
std::map<int, int> map1;

  std::pair<int, int> pair;
  pair = std::make_pair(10, 9);

  map1.insert(pair);

  for (size_t i = 0; i < 10; i++)
  {
    std::pair<int, int> pair;
    pair = std::make_pair(i, i);
    map1.insert(pair);

  }
  

  std::map<int, int>::iterator it;


  for (it = map1.begin() ; it != map1.end(); it++)
  {
     std::cout << it->first << "\n";
  }
  */
 
// 1) it equivale ad un ft::pair o value_type
// 2) node->data equivale al return di begin
// 3) ft::tree_iterator node equivale al puntatore nodo da iterare



 /*
    //creare una funzione che itera _first fino al nodo piu basso
    //prima finire di implementare tutta tree_iterator
    //correggere costruttori ecc. ed aggiungere tutte le altre cose
 */

}