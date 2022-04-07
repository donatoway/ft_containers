#include <iostream>
#include <queue>
#include <algorithm>
 #include "RBtree.hpp"
#include "pair.hpp"
#include "map.hpp"
#include <map>
#include <string>
#include <iomanip>
//#include "Tree_iterator.hpp"


int main()
{

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
  
  /* ft::pair<std::string, std::string>     pair_val;

    pair_val = ft::make_pair("1","2");

    ft::pair<std::string, std::string>     pair_val2;
    pair_val2 = ft::make_pair("alberto", "ciao");

     ft::pair<std::string, std::string>     pair_val3;
    pair_val3 = ft::make_pair("alberto", "zorro");

    ft::pair<std::string, std::string>     pair_val4;
    pair_val4 = ft::make_pair("osvaldo", "dino");
    ft::map<std::string, std::string> m;
  

    
      m.print2();
    */

  /*  std::pair<std::string, int> p;
    p = std::make_pair("a", 1);

    std::pair<std::string, int> p2;
    p2 = std::make_pair("b", 2);


    std::map<std::string, int> map1;
    map1.insert(p);
    map1.insert(p2);

    std::map<std::string, int> iter(map1.begin(), map1.end());
    std::cout << "\niter = "; print_map(iter);
    std::cout << "map1 = "; print_map(map1);
  */
 /*   ft::pair<std::string, int> p;
    p = ft::make_pair("a", 1);

    ft::pair<std::string, int> p2;
    p2 = ft::make_pair("b", 2);


    ft::map<std::string, int> map1;
    map1.insert(p);
    map1.insert(p2);

     ft::map<std::string, int> iter(map1.begin("anything"), map1.end());

    std::cout << "\niter = "; print_map(iter);
  */
    //continuare a costruire i costruttori di map

    
    return 0;
}