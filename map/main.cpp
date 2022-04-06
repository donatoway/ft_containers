#include <iostream>
#include <queue>
#include <algorithm>
 #include "RBtree.hpp"
#include "pair.hpp"
#include "map.hpp"

int main()
{
   ft::pair<std::string, std::string>     pair_val;

    pair_val = ft::make_pair("1","2");

    ft::pair<std::string, std::string>     pair_val2;
    pair_val2 = ft::make_pair("alberto", "ciao");

     ft::pair<std::string, std::string>     pair_val3;
    pair_val3 = ft::make_pair("alberto", "zorro");

    ft::pair<std::string, std::string>     pair_val4;
    pair_val4 = ft::make_pair("osvaldo", "dino");
   ft::map<std::string, std::string> m;


    m.insert(pair_val);
    m.insert(pair_val4);
    m.insert(pair_val3);
  

      m.print2();


    //continuare a costruire i costruttori di map

    
    return 0;
}