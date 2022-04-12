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
                typedef                 Key                                         key_type;
                typedef                 Compare                                     Key_compare;
                typedef                 T                                           mapped_type;
                typedef      typename   ft::pair<Key, T>                            value_type;
                typedef      typename   std::size_t                                 size_type;
                typedef                 Allocator                                   allocator_type;
                typedef      typename   allocator_type::pointer                     pointer;
                typedef      typename   ft::RBTree<value_type>                      tree;
                typedef      typename   ft::Map_iterator<value_type>                iterator;
                typedef      typename   ft::ConstMap_iterator<value_type>           Map_iterator_const;
                typedef      typename   ft::Map_Reverse_iterator<value_type>        Reverse_iterator;
                typedef     typename    ft::Const_Map_Reverse_iterator<value_type>  Const_Rev_Map_Iterator;

        private:
                value_type              other_node;
                pointer                 _first;
                pointer                 _end;
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
                    this->_map = obj._map;
                    this->_first = obj._first;
                    this->_end = obj._end;
                    this->_size = obj._size;
                }

                //assign
                map &operator=(const map &map)
                {
                    this->_map = map._map;
                    this->_first = map._first;
                    this->_end = map._end;
                    this->other_node = map.other_node;
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

                Map_iterator_const                          begin()const{ return Map_iterator_const(_first);};

                iterator                                    begin(){ return iterator(_first);};

                Map_iterator_const                           end()const{ return Map_iterator_const(_end);};

                iterator                                    end(){return iterator(_first->right);};

                Reverse_iterator                            rbegin(){ return (Map_Reverse_iterator<value_type>(_end));};

                Reverse_iterator                            rend(){ return (Map_Reverse_iterator<value_type>(_first->left));};

                Const_Map_Reverse_iterator<value_type>      rbegin()const{return Const_Map_Reverse_iterator<value_type>(_end);};

                Const_Map_Reverse_iterator<value_type>      rend()const{return(Const_Map_Reverse_iterator<value_type>(_first->left)); };


            // -------------------------- CAPACITY ----------------------------
                size_type size() const {return (this->_size);};

                size_type max_size() const{return (_allocation.max_size());};

                bool empty() const {return !(_size);};

            // ------------------------- ELEMENT ACCESS -----------------------

                //Se k è una chiave di un elemento nel container ritorna quella coppia di valori,
                //Altrimenti se k non esiste, inserisce una nuova coppia di valori Key = k
                mapped_type& operator[] (const key_type& k)
                {
                    iterator it;
                    //se esiste ritorna lélemento e il suo second
                    for (it = begin(); it != end(); it++)
                    {
                        if (it->first == k)
                            return (it->second);
                    }
                    //se non esiste lo crea, lo aggiunge ri-itera
                    //e ritorna quell elemento
                    other_node = ft::make_pair(k, mapped_type());
                    insert(other_node);

                    for (it = begin(); it != end(); it++)
                        if (it->first == k)
                            break;
                    return (it->second);
                }

            //------------------------- OPERATION -------------------------------

                iterator find (const key_type& k)
                {
                    //implementare search          
                }
                void print2(){print(_map);};
                
                void insert( const value_type& value )
                {
                    _size++;
                    _tree.insert(value);
                    _map =_tree.root;
                    _first = _tree.root;
                    _end = _tree.root;
                    while (_first->left)
                        _first = _first->left;
                    while (_end->right)
                        _end = _end->right; 
                }
                ~map()
                {
                  
                }
    };
}

#endif