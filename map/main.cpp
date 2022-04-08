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
  std::pair<int, int> qq;

  qq = std::make_pair(10,9);

  std::pair<int, int> qq2;

  qq2 = std::make_pair(20,9);

   std::pair<int, int> qq3;

  qq3 = std::make_pair(30,9);

    std::pair<int, int> qq4;

  qq4 = std::make_pair(40,9);


  std::map<int, int> map1;

  map1.insert(qq);
  map1.insert(qq2);
  map1.insert(qq3);
  map1.insert(qq4);



  std::map<int, int>::iterator a;




  for (a = map1.begin() ; a != map1.end(); a++)
  {
    std::cout << *a << "\n";
  }
  */

    ft::pair<int, int>   pai;

    pai = ft::make_pair(10, 10);

    ft::RBTree<ft::pair<int, int> >    a;
    ft::map<int, int>   map1;

    map1.insert(pai);

    a.insert(pai);
   // a.print();

    ft::map<int,int>::map_iterator it;

    it = map1.begin();
    //std::cout << it-> << "\n";
   // it = map1.begin();

   // std::cout << it.node->data.first << "\n";


   std::pair<int, int>   pai2;

    pai2 = std::make_pair(200, 10);
    std::map<int, int>   map2;

  map2.insert(pai2);

  std::map<int, int>::iterator it2;

  it2 = map2.begin();

  std::cout << it2->first << "\n";

  //- continuare ad implementare Tree_iterator
  //- begin deve ritornare il tree left left ecc. cioe il primo elemento
  //- l'iterator deve corrispondere nodo e al pair value


}