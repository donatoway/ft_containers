#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "../vector/iterators.hpp"
#include "map.hpp"
#include "Tree_iterator.hpp"
#include "utils_map.hpp"

namespace ft
{
    template <class K, class M>
    class Map_iterator
    {
        public:
                typedef     Node<K, M>*     pointer;
                typedef     ft::pair<K, M>  value_type;
        
        private:
                pointer     _node;

        pointer NextNode(pointer node)
        {
            pointer next;
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
			return (next);
        }

        pointer PreviousNode(pointer node)
		{
			pointer next;

			if (!node->left)
			{
				next = node;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = node->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};


        public:
                //-------- COSTRUTTORI ---------------
                Map_iterator():_node(0){};
                Map_iterator(pointer new_node):_node(new_node){};
                Map_iterator(const Map_iterator &other){*this = other;};
			    Map_iterator &operator=(const Map_iterator &other)
                {
                    _node = other._node;
                    return (*this);
                };

                //------------ OPERATOR --------------
                value_type &operator*(void) {return (_node->data);};

                value_type *operator->(void){return (&_node->data);};

                Map_iterator &operator++(void)
                {
                    _node = NextNode(_node);
                    return (*this);
                };

                Map_iterator operator++(int)
                {
                    Map_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                 Map_iterator &operator--(void)
                {
                    _node = PreviousNode(_node);
                    return (*this);
                };

                Map_iterator operator--(int)
                {
                    Map_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                };

                bool operator==(const Map_iterator<K, M> &other){return (_node == other._node);};
                bool operator!=(const Map_iterator<K, M> &other){return (!(*this == other));};
                bool operator>(const Map_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Map_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Map_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Map_iterator& bst_it){return (this->node <= bst_it.node);};

                //----- GET_NODE -------
                pointer getNode(){return (this->_node);};
    };

     template <class K, class M>
    class ConstMap_iterator
    {
        public:
                typedef     Node<K, M>*     pointer;
                typedef     ft::pair<K, M>  value_type;
        
        private:
                pointer     _node;

        pointer NextNode(pointer node)
        {
            pointer next;
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
			return (next);
        }

        pointer PreviousNode(pointer node)
		{
			pointer next;

			if (!node->left)
			{
				next = node;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = node->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};


        public:
                //-------- COSTRUTTORI ---------------
                ConstMap_iterator():_node(0){};
                ConstMap_iterator(const pointer new_node):_node(new_node){};
                ConstMap_iterator(const ConstMap_iterator &other){*this = other;};
			    ConstMap_iterator &operator=(const ConstMap_iterator &other)
                {
                    _node = other._node;
                    return (*this);
                };

                //------------ OPERATOR --------------
                value_type &operator*(void) const{return (_node->data);}

                value_type *operator->(void)const{return (&_node->data);}

                ConstMap_iterator &operator++(void)
                {
                    _node = NextNode(_node);
                    return (*this);
                };

                ConstMap_iterator operator++(int)
                {
                    ConstMap_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                 ConstMap_iterator &operator--(void)
                {
                    _node = PreviousNode(_node);
                    return (*this);
                };

                ConstMap_iterator operator--(int)
                {
                    ConstMap_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                };

                bool operator==(const ConstMap_iterator<K, M> &other){return (_node == other._node);};
                bool operator!=(const ConstMap_iterator<K, M> &other){return (!(*this == other));};
                bool operator>(const ConstMap_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const ConstMap_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const ConstMap_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const ConstMap_iterator& bst_it){return (this->node <= bst_it.node);};
                
                //----- GET_NODE -------
                pointer getNode(){return (this->_node);};
    };

    template <class K, class M>
    class Map_Reverse_iterator
    {
        public:
                typedef     Node<K, M>*     pointer;
                typedef     ft::pair<K, M>  value_type;
        
        private:
                pointer     _node;

        pointer NextNode(pointer node)
        {
            pointer next;
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
			return (next);
        }

        pointer PreviousNode(pointer node)
		{
			pointer next;

			if (!node->left)
			{
				next = node;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = node->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};


        public:
                //-------- COSTRUTTORI ---------------
                Map_Reverse_iterator():_node(0){};
                Map_Reverse_iterator(pointer new_node):_node(new_node){};
                Map_Reverse_iterator(const Map_Reverse_iterator &other){*this = other;};
			    Map_Reverse_iterator &operator=(const Map_Reverse_iterator &other)
                {
                    _node = other._node;
                    return (*this);
                };

                //------------ OPERATOR --------------
                value_type &operator*(void) {return (_node->data);};

                value_type *operator->(void){return (&_node->data);};

                Map_Reverse_iterator &operator++(void)
                {
                    _node = PreviousNode(_node);
                    return (*this);
                };

                Map_Reverse_iterator operator++(int)
                {
                    Map_Reverse_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                Map_Reverse_iterator &operator--(void)
                {
                    _node = NextNode(_node);
                    return (*this);
                };

                Map_Reverse_iterator operator--(int)
                {
                    Map_Reverse_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                };

                bool operator==(const Map_Reverse_iterator<K, M> &other){return (_node == other._node);};
                bool operator!=(const Map_Reverse_iterator<K, M> &other){return (!(*this == other));};
                bool operator>(const Map_Reverse_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Map_Reverse_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Map_Reverse_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Map_Reverse_iterator& bst_it){return (this->node <= bst_it.node);};

                //----- GET_NODE -------
                pointer getNode(){return (this->_node);};
    };

    template <class K, class M>
    class Const_Map_Reverse_iterator
    {
        public:
                typedef     Node<K, M>*     pointer;
                typedef     ft::pair<K, M>  value_type;
        
        private:
                pointer     _node;

        pointer NextNode(pointer node)
        {
            pointer next;
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
			return (next);
        }

        pointer PreviousNode(pointer node)
		{
			pointer next;

			if (!node->left)
			{
				next = node;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = node->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};


        public:
                //-------- COSTRUTTORI ---------------
                Const_Map_Reverse_iterator():_node(0){};
                Const_Map_Reverse_iterator(const pointer new_node):_node(new_node){};
                Const_Map_Reverse_iterator(const Const_Map_Reverse_iterator &other){*this = other;};
			    Const_Map_Reverse_iterator &operator=(const Const_Map_Reverse_iterator &other)
                {
                    _node = other._node;
                    return (*this);
                };

                //------------ OPERATOR --------------
                value_type &operator*(void)const {return (_node->data);};

                value_type *operator->(void)const{return (&_node->data);};

                Const_Map_Reverse_iterator &operator++(void)
                {
                    _node = PreviousNode(_node);
                    return (*this);
                };

                Const_Map_Reverse_iterator operator++(int)
                {
                    Const_Map_Reverse_iterator tmp(*this);
                    this->operator++();
                    return (tmp);
                };

                Const_Map_Reverse_iterator &operator--(void)
                {
                    _node = NextNode(_node);
                    return (*this);
                };

                Const_Map_Reverse_iterator operator--(int)
                {
                    Const_Map_Reverse_iterator tmp(*this);
                    this->operator--();
                    return (tmp);
                };

                bool operator==(const Const_Map_Reverse_iterator<K, M> &other){return (_node == other._node);};
                bool operator!=(const Const_Map_Reverse_iterator<K, M> &other){return (!(*this == other));};
                bool operator>(const Const_Map_Reverse_iterator& bst_it) { return (this->node > bst_it.node);};
                bool operator<(const Const_Map_Reverse_iterator& bst_it){return (this->node < bst_it.node);};		
                bool operator>=(const Const_Map_Reverse_iterator& bst_it){return (this->node >= bst_it.node);};
                bool operator<=(const Const_Map_Reverse_iterator& bst_it){return (this->node <= bst_it.node);};

                //----- GET_NODE -------
                pointer getNode(){return (this->_node);};
    };
};


#endif