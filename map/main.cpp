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


    ft::RBTree<ft::pair< int, int> > tree;
  ft::pair<int, int>      pai;
    for (int i = 0; i < 10; i++)
      {
         ft::pair<int, int>      pai;
          pai = ft::make_pair(i, i);

          tree.insert(pai);
      }
      ft::pair<int, int>      pai2;
    pai2 = ft::make_pair(9, 9);
   // tree.printInOrder();
     tree.deleteByVal(pai2);

     // tree.printLevelOrder();

    // COMPLETARE INSERT GLI ALTRI 2 COSTRUTTORI, DOPO STUDIARE DELETE IN TREE ED INIZIARE
    // AD IMPLEMENTARLO
  return 0;
}