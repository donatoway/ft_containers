#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "RBtree.hpp"
#include "Tree_iterator.hpp"



namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Node<ft::pair<Key, T> > > >
    class map
    {
        public:
                typedef                 Key                             key_type;
                typedef                 Compare                         Key_compare;
                typedef                 T                               mapped_type;
                typedef      typename   ft::pair<Key, T>                value_type;
                typedef      typename   std::size_t                     size_type;
                typedef                 Allocator                       allocator_type;
                typedef      typename   allocator_type::pointer         pointer;
                typedef      typename   ft::RBTree<value_type>          tree;
                typedef      typename   ft::Tree_iterator<value_type>   map_iterator;


        private:
                pointer                 _first;
                tree                    _tree;
                pointer                 _map;
                allocator_type          _allocation;
                size_type               _size;
        public:
                // costruttore di default
                explicit map( const Compare& comp = Key_compare() ,  const Allocator& alloc = Allocator() ) :  _allocation(alloc)
                {
                    _allocation.allocate(0);
                    _size = 0;
                    _first = NULL;
                }

                // Range constructor
                // Costruisce un container con elementi da firts-last, con ogni elemento costruito dal suo corrispndente elemento
                template <class InputIterator>
                map (InputIterator first, InputIterator last, const Key_compare& comp = Key_compare(),\
                        const allocator_type& alloc = allocator_type())
                {
                    _size = 0;

                    for (; first != last; ++first)
                    {
                        _tree.insert(*first);
                    }
                    _map = _tree;
                    
                }

                // Copy constructor
                map(const map& obj): _allocation(obj._allocation)
                {
                    this->_tree = obj._tree;
                    this->_map = _tree;
                }

                //assign
                map &operator=(const map &map)
                {
                    this->_map = map._map;
                    this->_allocation = map._allocation;
                    this->_tree = map._tree;
                    this->_size = map._size;
                    return (*this);
                }

                void print(Node<value_type> *_map)
                {
                    if (_map == NULL)
                    return;
            
                    print(_map->left);
                    std::cout << _map->data.first <<  " " << _map->data.second << "\n";
                    print(_map->right);
                    
                }



            //--------------------- ITERATOR ------------------------------

                //creare una funzione che itera _first fino al nodo piu basso
                //prima finire di implementare tutta tree_iterator
                //correggere costruttori
                map_iterator begin(){return map_iterator(_first);};




                void print2(){print(_map);};
                
                void insert( const value_type& value )
                {
                    _size++;
                    _tree.insert(value);
                    _map =_tree.root;
                    _first = _map;
                }

                ~map()
                {
                  
                }
    };
}

#endif