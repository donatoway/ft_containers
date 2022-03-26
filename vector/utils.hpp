#ifndef UTILS_HPP
#define UTILS_HPP

#include "vector.hpp"

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
};

#endif