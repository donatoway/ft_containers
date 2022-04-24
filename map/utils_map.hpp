#ifndef UTILS_MAP_HPP
#define UTILS_MAP_HPP

#include "utils_map.hpp"

namespace ft
{
    template <class Arg1, class Arg2, class Result>
            struct binary_function
            {
                typedef Arg1 first_argument_type;

                typedef Arg2 second_argument_type;

                typedef Result result_type;
            };

    template <class T>
            struct less : binary_function<T, T, bool>
            {
                bool operator() (const T& x, const T& y) const { return (x < y); }
            };

             template <typename U>
                void swap(U& a, U& b)
                {
                    U tmp = a;
                    a = b;
                    b = tmp;
                }

    template <class Key, class T>
	struct Node
	{
		ft::pair<Key, T> data;
		Node *left;
		Node *right;
		Node *parent;
		bool end;
	};
}


#endif