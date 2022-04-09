#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../vector/iterators.hpp"
#include "RBtree.hpp"
#include "map.hpp"

namespace ft
{
    template < class  value>
    class Map_iterator
    {
        public:
                typedef     value                                           value_type; //coppia
                typedef     typename ft::Node<value_type>*                  iterator;       //tree
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;

        private:
                iterator      node;
        public:

        // --------------- CONSTRUCTOR -------------------------
                //Costruttore vuoto
                Map_iterator(){};

                //Costruttore di default che ha come parametro un nodo e ne costruisce
                //Un iteratore con un nodo che punta allo stesso nodo
                Map_iterator(Node<value_type> *obj){node = obj;};

                //Copy Constructor : crea un const map_iterator che punta allo stesso nodo
                Map_iterator(const Map_iterator &obj){node = obj.node;}

                //Assegnazione
                Map_iterator& operator=(const Map_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
          // ----------------- OPEARATOR -------------------------
                //pointer and reference  
                reference       operator*() { return node->data; }
                pointer         operator->() { return &node->data; }

                Map_iterator    &operator++(void)
                {
                    iterator next;
                    if (!node->right)
                    {
                        next = node;
                        while (next->parent && next == next->parent->right)
                            next = next->parent;
                        next = next->parent;
                    }
                    else
                    {
                        next = node->right;
                        while (next->left)
                            next = next->left;
                    }
                    if (next != NULL)
                        this->node = next;
                    return (*this);
                };

                Map_iterator    operator++(int)
                {
                   Map_iterator tmp(*this);
                   this->operator++();
                   return (tmp);
                };

                Map_iterator &operator--(void)
                {
                    iterator previous;
                    if (!node->left)
                    {
                        previous = node;
                        while (previous->parent && previous == previous->parent->left)
                            previous = previous->parent;
                        previous = previous->parent;
                    }
                    else
                    {
                        previous = node->left;
                        while (previous->right)
                            previous = previous->right;
                    }
                    if (previous != NULL)
                        this->node = previous;
                    return (*this);
                };

                Map_iterator operator--(int)
                {
                    Map_iterator tmp(*this);
                   this->operator--();
                   return (tmp);
                }
            bool operator==(const Map_iterator& bst_it) { return (this->_node == bst_it.node); };
            bool operator!=(const Map_iterator& bst_it) { return (this->node != bst_it.node); };     
    };
};

#endif