#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "RBtree.hpp"
#include "pair.hpp"


/*
    Map riceve 2 parametri: sostanzialmente il primo definisce Il tipo di Chiave (esempio int, char, string ecc.)
    il secondo parametro definisce il Tipo del valore associato a quella chiave 


*/
namespace ft
{      /* Tipo della chiave - Mapped value - key_compare - allocazione allocator_type */
    template < class Key,  class T,  class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        typedef typename    Key                                     key_type;
        typedef typename    T                                       mapped_type;
        typedef typename    std::pair<key_type, mapped_type>        value_type;
        typedef typename    std::less<key_type>                     key_compare;
        //

    };  




}

#endif
