#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../vector/iterators.hpp"
#include "RBtree.hpp"
#include "map.hpp"

namespace ft
{
    template < class  value>
    class Tree_iterator
    {
        public:
                typedef     value                                   value_type; //coppia
                typedef     ft::RBTree<value_type>                  tree;       //tree

        public:
                tree iter;
        public:
                //Costruttore vuoto
                Tree_iterator() {};

                //Costruttore Con un Tree
                Tree_iterator(const tree &obj)
                {
                    iter.root = obj.root;
                }
                //Assegnazione
                Tree_iterator& operator=(const Tree_iterator& obj)
                {
                    this->iter = obj.iter;
                    return (*this);
                }
    };
};




#endif