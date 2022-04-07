#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../vector/iterators.hpp"
#include "RBtree.hpp"
#include "map.hpp"

namespace ft
{
    template < class  key>
    class Tree_iterator
    {
        public:
                typedef key                                         value_type;
           //     typedef V                                         mapped_type;
                typedef   ft::Node<value_type>                      pointer;

        public:
                pointer _root;
        

        public:
                Tree_iterator()
                {
                    _root;
                }



    };
};




#endif