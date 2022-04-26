#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"
#include <iostream>

namespace ft
{

//--------------------- ENABLE_IF   ---------------------------------
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };




//--------------------- IS_INTEGRAL ---------------------------------
    //STRUCT BASE : INTEGRAL_CONSTANT
    template <bool bool_type, typename t_value>
    struct integral_constant
    {
        typedef t_value type_val;
        static const bool value = bool_type;
    };

    //STRUCT DERIVATA : IS_INTEGRAL

    template<typename T>
    struct is_integral : public integral_constant<false, bool>{};

    template <>
    struct is_integral<bool> :public integral_constant<true, bool>{};

    template <>
    struct is_integral<char> :public integral_constant<true, char>{};

    template <>
    struct is_integral<signed char> :public integral_constant<true, signed char>{};

    template <>
    struct is_integral<short> : public integral_constant<true, short>{};

    template <>
    struct is_integral<int> : public integral_constant<true, int>{};

    template <>
    struct is_integral<long> : public integral_constant<true, long>{};

    template <>
    struct is_integral<long long> : public integral_constant<true, long long>{};

    template <>
    struct is_integral<unsigned char> : public integral_constant<true, unsigned char>{};

    template <>
    struct is_integral<unsigned int> : public integral_constant<true, unsigned int>{};

    template <>
    struct is_integral<unsigned long int> : public integral_constant<true, unsigned long int>{};

    template <>
    struct is_integral<unsigned long long int> : public integral_constant<true, unsigned long long int>{};


//----------------- LEXICOGRAPHICAL_COMPARE --------------------------
    //lexicographical_compare : - controlla che il primo range first1-last1 è minore di first2-last2
    //        - gli elementi sono comparati con <
    //        - gli elementi sono comparati uno ad uno ed il primo elemento diverso definisce se
    //        - quale è minore e quale è maggiore

   // template<class InputIt1, class InputIt2>
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
    }

    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2,
                                Compare comp)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (comp(*first1, *first2)) return true;
            if (comp(*first2, *first1)) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
};

#endif