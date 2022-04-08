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
                typedef     value                                           value_type; //coppia
                typedef     typename ft::Node<value_type>                   iterator;       //tree
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;

        private:
                Node<value_type>     *node;
        public:
                //Costruttore vuoto
                Tree_iterator(){};

                //Costruttore Con un Tree
               Tree_iterator(const Tree_iterator &obj)
                {
                    node = obj.node;
                }

                Tree_iterator(Node<value_type> *obj)
                {
                    node = obj;
                }
                //Assegnazione
                Tree_iterator& operator=(const Tree_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
                
                reference operator*() { return node->data; }
                pointer operator->() { return &node->data; }
                
    };
};




#endif