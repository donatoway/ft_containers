#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "RBtree.hpp"


namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Node<ft::pair<Key, T> > > >
    class map
    {
        public:
                typedef                 Key                         key_type;
                typedef                 T                           mapped_type;
                typedef      typename   ft::pair<Key, T>            value_type;
                typedef      typename   std::size_t                 size_type;
                typedef                 Allocator                   allocator_type;
                typedef      typename   allocator_type::pointer     pointer;
                typedef      typename   ft::RBTree<value_type>     tree;
        private:
                tree                    _tree;
                pointer                 _map;
                allocator_type          _allocation;
                size_type               _size;
        public:
                // costrutore di base
                map() :_size(0), _map(NULL) {};
                //
                explicit map( const Compare& comp,  const Allocator& alloc = Allocator() ) :  _allocation(alloc)
                {
                    _allocation.allocate(0);
                    _size = 0;
                }
                void print(Node<value_type> *_map)
                {
                    if (_map == NULL)
                    return;
            
                    print(_map->left);
                    std::cout << _map->data.first <<  " " << _map->data.second << "\n";
                    print(_map->right);
                    
                }

                void print2(){print(_map);};
                
                void insert( const value_type& value )
                {
                    _size++;
                    _tree.insert(value);
                    _map =_tree.root;
                }

                ~map()
                {
                  
                }
    };
}

#endif