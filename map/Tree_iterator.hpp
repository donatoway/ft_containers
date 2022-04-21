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
                typedef     value                                           value_type;
                typedef     typename ft::Node<value_type>*                  iterator;
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;
        public:
                iterator      node;
        public:

        // --------------- CONSTRUCTOR -------------------------
                //Costruttore vuoto
                Map_iterator(){};

                //Costruttore di default che ha come parametro un nodo e ne costruisce
                //Map_iterator con un nodo che punta allo stesso nodo
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
                   // if (next != NULL)
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
                  //  if (previous != NULL)
                        this->node = previous;
                    return (*this);
                };

                Map_iterator operator--(int)
                {
                    Map_iterator tmp(*this);
                   this->operator--();
                   return (tmp);
                }
        
                bool operator==(const Map_iterator& bst_it) { return (this->node == bst_it.node); };
                bool operator!=(const Map_iterator& bst_it) { return !(*this == bst_it);};     
                bool operator>(const Map_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Map_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Map_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Map_iterator& bst_it){return (this->node <= bst_it.node);};
    };


    template < class  value>
    class ConstMap_iterator
    {
        public:
                typedef     value                                           value_type;
                typedef     typename ft::Node<value_type>*                  iterator;      
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;

        private:
                iterator      node;
        public:

        // --------------- CONSTRUCTOR -------------------------
                //Costruttore vuoto
                ConstMap_iterator():node(0){};

                //Costruttore di default che ha come parametro un nodo e ne costruisce
                //Map_iterator con un nodo che punta allo stesso nodo
                ConstMap_iterator(const iterator &obj): node(obj) {};

                //Copy Constructor : crea un const map_iterator che punta allo stesso nodo
                ConstMap_iterator(const ConstMap_iterator &obj){node = obj.node;}

                //Assegnazione
                ConstMap_iterator& operator=(const ConstMap_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
          // ----------------- OPEARATOR -------------------------
                //pointer and reference  
                reference       operator*() { return node->data; }const
                pointer         operator->() { return &node->data; }const

                ConstMap_iterator    &operator++(void)
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
                 //   if (next != NULL)
                        this->node = next;
                    return (*this);
                };

                ConstMap_iterator    operator++(int)
                {
                   ConstMap_iterator tmp(*this);
                   this->operator++();
                   return (tmp);
                };

                ConstMap_iterator   &operator--(void)
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
                   // if (previous != NULL)
                        this->node = previous;
                    return (*this);
                };

                ConstMap_iterator operator--(int)
                {
                    ConstMap_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                }
        
                bool operator==(const ConstMap_iterator& bst_it) { return (this->node == bst_it.node); };
                bool operator!=(const ConstMap_iterator& bst_it) { return !(*this == bst_it);};     
                bool operator>(const ConstMap_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const ConstMap_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const ConstMap_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const ConstMap_iterator& bst_it){return (this->node <= bst_it.node);};
    };


    template < class  value>
    class Map_Reverse_iterator
    {
        public:
                typedef     value                                           value_type;
                typedef     typename ft::Node<value_type>*                  iterator;
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;
        private:
                iterator      node;
        public:

        // --------------- CONSTRUCTOR -------------------------
                //Costruttore vuoto
                Map_Reverse_iterator(){};

                //Costruttore di default che ha come parametro un nodo e ne costruisce
                //Map_iterator con un nodo che punta allo stesso nodo
                Map_Reverse_iterator(Node<value_type> *obj){node = obj;};

                //Copy Constructor : crea un const map_iterator che punta allo stesso nodo
                Map_Reverse_iterator(const Map_Reverse_iterator &obj){node = obj.node;}

                //Assegnazione
                Map_Reverse_iterator& operator=(const Map_Reverse_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
          // ----------------- OPEARATOR -------------------------
                //pointer and reference  
                reference       operator*() { return node->data; }
                pointer         operator->() { return &node->data; }

                Map_Reverse_iterator    &operator++(void)
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
                  //  if (previous != NULL)
                        this->node = previous;
                    return (*this);
                }

                Map_Reverse_iterator    operator++(int)
                {
                    Map_Reverse_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                Map_Reverse_iterator &operator--(void)
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
                 //   if (next != NULL)
                        this->node = next;
                    return (*this);
                };

                Map_Reverse_iterator operator--(int)
                {
                    Map_Reverse_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                }
        
                bool operator==(const Map_Reverse_iterator& bst_it) { return (this->node == bst_it.node); };
                bool operator!=(const Map_Reverse_iterator& bst_it) { return !(*this == bst_it); };     
                bool operator>(const Map_Reverse_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Map_Reverse_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Map_Reverse_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Map_Reverse_iterator& bst_it){return (this->node <= bst_it.node);};
    };

    template < class  value>
    class Const_Map_Reverse_iterator
    {
        public:
                typedef     value                                           value_type;
                typedef     typename ft::Node<value_type>*                  iterator;
                typedef     value_type*                                     pointer;
                typedef     value_type&                                     reference;
        private:
                iterator      node;
        public:

        // --------------- CONSTRUCTOR -------------------------
                //Costruttore vuoto
                Const_Map_Reverse_iterator(){};

                //Costruttore di default che ha come parametro un nodo e ne costruisce
                //Map_iterator con un nodo che punta allo stesso nodo
                Const_Map_Reverse_iterator(Node<value_type> *obj){node = obj;};

                //Copy Constructor : crea un const map_iterator che punta allo stesso nodo
                Const_Map_Reverse_iterator(const Const_Map_Reverse_iterator &obj){node = obj.node;}

                //Assegnazione
                Const_Map_Reverse_iterator& operator=(const Const_Map_Reverse_iterator& obj)
                {
                    this->node = obj.node;
                    return (*this);
                }
          // ----------------- OPEARATOR -------------------------
                //pointer and reference  
                reference       operator*() { return node->data; }const
                pointer         operator->() { return &node->data; }const

                Const_Map_Reverse_iterator    &operator++(void)
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
                  //  if (previous != NULL)
                        this->node = previous;
                    return (*this);
                }

                Const_Map_Reverse_iterator    operator++(int)
                {
                    Const_Map_Reverse_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                Const_Map_Reverse_iterator &operator--(void)
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
                 //   if (next != NULL)
                        this->node = next;
                    return (*this);
                };

                Const_Map_Reverse_iterator operator--(int)
                {
                    Const_Map_Reverse_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                }
        
                bool operator==(const Const_Map_Reverse_iterator& bst_it) { return (this->node == bst_it.node); };
                bool operator!=(const Const_Map_Reverse_iterator& bst_it) { return !(*this == bst_it); };     
                bool operator>(const Const_Map_Reverse_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Const_Map_Reverse_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Const_Map_Reverse_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Const_Map_Reverse_iterator& bst_it){return (this->node <= bst_it.node);};
    };
};


#endif