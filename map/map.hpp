#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "RBtree.hpp"
#include "Tree_iterator.hpp"
#include "utils_map.hpp"



namespace ft
{
    template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<Node<ft::pair<Key, T> > > >
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
                typedef      typename   ft::RBTree<value_type, key_type>            tree;
                typedef      typename   ft::Map_iterator<value_type>                iterator;
                typedef      typename   ft::ConstMap_iterator<value_type>           Map_iterator_const;
                typedef      typename   ft::Map_Reverse_iterator<value_type>        Reverse_iterator;
                typedef     typename    ft::Const_Map_Reverse_iterator<value_type>  Const_Rev_Map_Iterator;

                class value_compare
			    {
                    friend class map;
                    protected:
                        Compare comp;
                        value_compare (Compare c) : comp(c) {};
                    public:
                        typedef bool result_type;
                        typedef value_type first_argument_type;
                        typedef value_type second_argument_type;
                        bool operator() (const value_type& x, const value_type& y) const
                        {
                            return comp(x.first, y.first);
                        };
			    };
        public:
              //  pointer                 _first;
             //   pointer                 _end;
                tree                    _tree;
             //  pointer                 _map;
                allocator_type          _allocation;
                size_type               _size;
        public:
                // costruttore di default
                explicit map( const Compare& comp = Key_compare() ,  const Allocator& alloc = Allocator() )
                {
                    _tree.root = NULL;
                    _tree.pt = NULL;
                    _tree._size = 0;
                   // _first = NULL;
                }

                // Range constructor
                // Costruisce un container con elementi da firts-last, con ogni elemento costruito dal suo corrispndente elemento
                template <class InputIterator>
                map (InputIterator first, InputIterator last, const Key_compare& comp = Key_compare(),\
                        const allocator_type& alloc = allocator_type())
                {
                    _tree.root = NULL;
                    _tree.pt = NULL;
                    _tree._size = 0;
                  //  _first = NULL;
                    for (; first != last; ++first)
                    {
                        _tree.insert(*first);
                    }
                 //   _map = _tree;
                    
                }

                // Copy constructor
                map(const map& obj)
                {
                    this->_tree._allocation = obj._tree._allocation;
                    this->_tree = obj._tree;
                 //   this->_map = obj._map;
                //    this->_first = obj._first;
                //    this->_end = obj._end;
                    this->_size = obj._size;
                }

                //assign
                map &operator=(const map &map)
                {
                //    this->_map = map._map;
                 //   this->_first = map._first;
                 //   this->_end = map._end;
                    this->_tree._allocation = map._tree._allocation;
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

                Map_iterator_const                          begin()const
                {
                    Node<value_type>* _first = _tree.root;
                    if (!_first->left && !_first->right)
                        return (end());
                    if (!_first->left && _first->right)
                        _first = _first->right;
                    while (_first->left)
                        _first = _first->left;
                    return Map_iterator_const(_first);
                };

                iterator                                    begin()
                { 
                    Node<value_type>* _first = _tree.root;
                    if (!_first->left && !_first->right)
                        return (end());
                    if (!_first->left && _first->right)
                        _first = _first->right;
                    while (_first->left)
                        _first = _first->left;
                    return iterator(_first);
                };
                pointer   _end(void) const
                {
                    return (_tree.root->right);
                };

                Map_iterator_const                           end()const
                {
                    Node<value_type> *_end = _tree.root;
                    while (_end->right)
                        _end = _end->right;
                    return Map_iterator_const(_end->right);
                };

                iterator                                    end()
                {
                    Node<value_type> *_end1 = _tree.root;
                    while (_end1->right)
                        _end1 = _end1->right;
                    return iterator(_end());
                };

                Reverse_iterator                            rbegin()
                {
                    Node<value_type> *_end = _tree.get_root();
                    while (_end->right)
                        _end = _end->right;
				    return (Reverse_iterator(_end));
                };

                Reverse_iterator                            rend()
                {
                    Node<value_type>* _first = _tree.get_root();
                    if (!_first->left && !_first->right)
                        return (_first->right);
                    if (!_first->left && _first->right)
                        _first = _first->right;
                    while (_first->left)
                        _first = _first->left;
                     return (Map_Reverse_iterator<value_type>(_first->left));
                };

                Const_Map_Reverse_iterator<value_type>      rbegin()const
                {
                   Node<value_type> *_end = _tree.root;
                    while (_end->right)
                        _end = _end->right;
				    return (Const_Rev_Map_Iterator(_end));
                };

                Const_Map_Reverse_iterator<value_type>      rend()const
                {
                    Node<value_type>* _first = _tree.root;
                    if (!_first->left && !_first->right)
                        return (_first->right);
                    if (!_first->left && _first->right)
                        _first = _first->right;
                    while (_first->left)
                        _first = _first->left;
                     return (Const_Map_Reverse_iterator<value_type>(_first->left));
                };


            // -------------------------- CAPACITY ----------------------------
                size_type size() const {return (this->_size);};

                size_type max_size() const{return (_allocation.max_size());};

                bool empty() const {return !(_size);};

            // ------------------------- ELEMENT ACCESS -----------------------

                //Se k è una chiave di un elemento nel container ritorna quella coppia di valori,
                //Altrimenti se k non esiste, inserisce una nuova coppia di valori Key = k
                mapped_type& operator[] (const key_type& k)
                {
                    iterator it = find(k);
                    if (it == end()) //se non esiste it = insert
                        insert(ft::make_pair(k, mapped_type()));
                    it = find(k);
                    return (it->second);
                }

            //------------------------- OPERATION -------------------------------

                iterator find (const key_type& k)
                {
                    pointer temp = _tree.get_root();
                        
                    while (temp != NULL)
                    {
                        if (k < temp->data.first)
                        {
                            if (temp->left == NULL)
                                break;
                            else
                                temp = temp->left;
                        }
                        else if (k == temp->data.first)
                            break;
                        else
                        {
                            if (temp->right == NULL)
                                break;
                            else
                                temp = temp->right;
                        }
                    }
                    iterator it = temp;
                        return it;
                }
                //count: trova il parametro k, se è presente ritorna 1 altrimenti 0
                size_type count (const key_type& k) const
                {
                    size_t c = 0;
                    ConstMap_iterator<value_type> it;

                    for (it = begin(); it != end(); it++)
                        if (it->first == k)
                            return (1);
                    return (0);
                }


             //   void print2(){print(_map);};
            

        
        //--------------------------- MODIFIERS ------------------------------
                
                void insert( const value_type& value )
                {
                    _tree.insert(value); 
                    _size = _tree.size();
                }

                //swap : scambia il contenuto del container con quello passato come parametro
                template <typename U>
                void swap(U& a, U& b)
                {
                    U tmp = a;
                    a = b;
                    b = tmp;
                }

                void swap (map& x)
                {
                    swap(this->_tree, x._tree);
                    swap(this->_tree._allocation, x._tree._allocation);
                 //   swap(this->_allocation,x._allocation);
                    swap(this->_size,x._size);
                 //   swap(this->_end ,x._end);
                 //   swap(this->_first,x._first);
                } 

                size_type erase (const key_type& k)
                {
                   _tree.deleteByVal(k);
                   _size = _tree._size;
                    return (_size);
                }

                 void erase (iterator position)
                 {   
                    erase(position.node->data.first);
                 }

                 void erase (iterator first, iterator last)
                 {
                     while (first != last)
                     {
                          Node<value_type> *tmp = first.node;
                          _tree.deleteByVal(tmp->data.first);
                          first++;
                     } 
                 }

        //-------------------------------- OBSERVES -------------------------------
                //ritorna una copia della comparazione della chiave
                Key_compare     key_comp() const {return (Compare());};

                //ritorna un oggetto di comparazione
                value_compare   value_comp() const {return (value_compare(Key_compare()));};
                
                
                ~map()
                {
                    
                }
        //--------------------------- ALLOCATORS --------------------
        allocator_type get_allocator() const {return (_tree._allocation);};
    };
}

#endif