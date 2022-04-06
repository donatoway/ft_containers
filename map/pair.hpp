#ifndef PAIR_HPP
#define PAIR_HPP
#include <iostream>

namespace ft
{
    template<class T1, class T2 >
    struct pair
    {
        public:
                typedef T1 type_1;
                typedef T2 type_2;

                type_1  first;
                type_2  second;

        pair(): first(), second(){};
        pair(const type_1 a, const type_2 b): first(a), second(b){};
        template <class one, class two>
	    pair (const pair<one, two>& pr): first(pr.first), second(pr.second) {};

        pair& operator= (const pair& pr)
        {
            if (*this == pr)
                return (*this);
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
  
    };

    template< class T1, class T2 >
    bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };
    template< class T1, class T2 >
    bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return !(lhs == rhs);
    }
    template <class T1, class T2>
    bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class T1, class T2>
    ft::pair<T1,T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
}


#endif