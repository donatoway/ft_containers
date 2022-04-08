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
                typedef     typename ft::Node<value_type>::data             iterator;       //tree
               // typedef     typename ft::map<value_type>::
        private:
                Node<value_type>     node;
              //  value_type          *pair_val;
        public:
                //Costruttore vuoto
                Tree_iterator(){};

                Tree_iterator(value_type &val)
                {
                    node.data = val;
                };

                Tree_iterator(iterator val)
                {
                    node.data = val;
                };

                //Costruttore Con un Tree
               Tree_iterator(const Tree_iterator &obj)
                {
                    node = obj.node;
                 //   std::cout << node->data.first << "\n";
                   // return (*this);
                }

                Tree_iterator(Node<value_type> *obj)
                {
                    node = obj;
                 ///   std::cout << node->data.first << "\n";
                   // return (*this);
                }
                //Assegnazione
                Tree_iterator& operator=(const Tree_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
                
    };
};




#endif