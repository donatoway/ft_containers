#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "Tree_iterator.hpp"
#include "utils_map.hpp"
#include "map.hpp"



namespace ft
{

    template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<Node< Key, T> > >
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
                typedef                 Node<Key,T>                                 Node;
                typedef      typename   ft::Map_iterator<Key, T>                    iterator;
                typedef      typename   ft::ConstMap_iterator<Key, T>               Map_iterator_const;
                typedef      typename   ft::Map_Reverse_iterator<Key, T>            Reverse_iterator;
                typedef     typename    ft::Const_Map_Reverse_iterator<Key, T>      Const_Rev_Map_Iterator;

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
        private:
                value_type              _pair_value;
                pointer                 _root;
                Key_compare              _comp;
                allocator_type          _allocation;
                size_type               _size;

                pointer _new_node(key_type key, mapped_type value, pointer parent, bool end = false)
                {

                    Node* new_node =  _allocation.allocate(1);
                    _allocation.construct(new_node);
                    new_node->right= 0;
                    new_node->left = 0;
                    new_node->parent = parent;
                    new_node->end = end;
                    new_node->data = ft::make_pair(key, value);
                    return (new_node);
                };

                Node* _insert_node(Node* n, key_type key, mapped_type value, bool end = false)
                {
                    if (n->end)
                    {
                        if (!n->left)
                        {
                            n->left = _new_node(key, value, n, end);
                            return (n->left);
                        }
                        return (_insert_node(n->left, key, value));
                    }
                    if (key < n->data.first && !end)
                    {
                        if (!n->left)
                        {
                            n->left = _new_node(key, value, n, end);
                            return (n->left);
                        }
                        else
                            return (_insert_node(n->left, key, value));
                    }
                    else
                    {
                        if (!n->right)
                        {
                            n->right = _new_node(key, value, n, end);
                            return (n->right);
                        }
                        else
                            return(_insert_node(n->right, key, value));
                    }

                };

                void    print(std::string str = 0, Node* n = 0)
                {
                        std::cout << n->data.first << " : " << str << "\n";
                }

                void Print_in_order(Node *x)
                {
                    if (x == NULL)
                    return;
                    Print_in_order(x->left);
                    std::cout << "first " << x->data.first << " second " << x->data.second << std::endl;
                    Print_in_order(x->right);
                }

                Node* _find(Node *n, key_type key) const
                {
                    Node* tmp;
                    if (!n->end && n->data.first == key && n->parent)
                        return (n);
                    if (n->right)
                    {
                        if ((tmp = _find(n->right, key)))
                            return (tmp);
                    }
                    if (n->left)
                    {
                        if ((tmp = _find(n->left, key)))
                            return (tmp);
                    }
                    return (0);
                };

                void _delete_node(Node* n)
                {
                    Node* parent = n->parent;
                    if (!n->left && !n->right)
                    {
                        if (parent->right == n)
                            parent->right = 0;
                        else
                            parent->left = 0;
                        delete n;
                        return ;
                    }
                    if (n->right && !n->left)
                    {
                        if (parent->right == n)
                            parent->right = n->right;
                        else
                            parent->left = n->right;
                        n->right->parent = parent;
                        delete n;
                        return ;
                    }
                    if (n->left && !n->right)
                    {
                        if (parent->right == n)
                            parent->right = n->left;
                        else
                            parent->left = n->left;
                        n->left->parent = parent;
                        delete n;
                        return ;
                    }
                    Node* next = (++iterator(n)).getNode();
                    if (!next)
                        next = (--iterator(n)).getNode();
                    ft::swap(next->data,n->data);
                    _delete_node(next);
                };
        public:
                // costruttore di default
                explicit map( const Compare& comp = Key_compare() ,  const Allocator& alloc = Allocator() ):
                _allocation(alloc), _comp(comp)
                {
                    _root = _new_node(key_type(), mapped_type(), 0);
                    _root->right = _new_node(key_type(), mapped_type(), _root, true);
                    _size = 0;            
                }
              
                //------------------- ITERATOR -------------------

                iterator begin(void)
                {
                    Node *n = _root;
                    if (!n->left && !n->right)
                        return (end());
                    if (!n->left && n->right)
                        n = n->right;
                    while (n->left)
                        n = n->left;
                    return (iterator(n));
                };

                iterator end(void)
                {
                    return (iterator(_root->right));
                };

                Map_iterator_const begin(void)const
                {
                    Node *n = _root;
                    if (!n->left && !n->right)
                        return (end());
                    if (!n->left && n->right)
                        n = n->right;
                    while (n->left)
                        n = n->left;
                    return (Map_iterator_const(n));
                };

                Map_iterator_const end(void)const
                {
                    return (Map_iterator_const(_root->right));
                };

                Reverse_iterator rbegin(void)
                {
                    iterator i = end();
                    i--;
                    return (Reverse_iterator(i.getNode()));
                };
                Const_Rev_Map_Iterator rbegin(void) const
                {
                    Map_iterator_const i = end();
                    i--;
                    return (Const_Rev_Map_Iterator(i.getNode()));
                };
                Reverse_iterator rend(void)
                {
                    return (Reverse_iterator(this->_root));
                };
                Const_Rev_Map_Iterator rend(void) const
                {
                    return (Const_Rev_Map_Iterator(_root));
                };




                //---------------

                bool empty(void) const
                {
                    return (_size == 0);
                };
                iterator find(const key_type &value)
                {
                    if (empty())
                        return (end());
                    Node* tmp = _find(_root, value);
                    if (tmp)
                        return (iterator(tmp));
                    return (end());
                };


                // -------------- MODIFIERS -------------------
                ft::pair<iterator, bool> insert(const value_type &value)
                {
                    iterator tmp;

                    if ((tmp = find(value.first)) != end())
                        return (ft::make_pair(tmp, false));
                    _size++;
                    return (ft::make_pair(iterator(_insert_node(_root, value.first, value.second)), true));
                };

                iterator insert (iterator position, const value_type& val)
                {
                    insert(val);
                    return  (position);
                }

                void insert (iterator first, iterator last)
                {
                    while (first != last)
                    {
                         insert(*first);
                         first++;
                    }
                }

                void erase(iterator position)
                {
                    _delete_node(position.getNode());
                    --_size;
                };

                size_type erase(const key_type &value)
                {
                    int i = 0;
                    iterator item;
                    while ((item = find(value)) != end())
                    {
                        erase(item);
                        ++i;
                    };
                    return (i);
                };

                void erase(iterator first, iterator last)
                {
                    while (first != last)
                        erase(first++);
                };

                void swap (map& x)
                {
                    swap(this->_root, x._root);
                    swap(this->_size, x._size);
                } 
            
    };
}

#endif