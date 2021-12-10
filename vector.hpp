#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils.hpp"
#include <iostream>

namespace ft
{

    template < class T, class alloc = std::allocator<T> >
    class vector
    {
        public:
                typedef T                                               value_type;
                typedef alloc                                           allocator_type;
                typedef typename allocator_type::size_type              size_type;
                typedef typename std::ptrdiff_t                         difference_type;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::const_reference        const_reference;
                typedef typename allocator_type::pointer                pointer;      
                typedef typename allocator_type::const_pointer          const_pointer;
                //Ci sono 4 tipi di costruttore:
                //default, fill, range, copy

                //default (costruisce un vettore senza elementi)
                explicit vector (const allocator_type& Allocator  = allocator_type()):
                _vector(nullptr), _allocation(Allocator), _size(0), _capacity(0)
                {
                    _vector = _allocation.allocate(0);
                };

                //Fill Constructor (costruisce un vettore con n elementi, ed ogni elemento è una copia di val)

                explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& Allocator = allocator_type()):_allocation(Allocator), _size(n)
                {
                    _vector = _allocation.allocate(n);
                    
                    for (size_t i = 0; i < n; ++i)
                        _allocation.construct(&_vector[i], val);
                };

                //Range Constructor (costruisce un vettore con tanti elementi quanto il range [first last] , con
                    //ogni elemento costruito dal suo corrispondente elemento in quella posizione del range, nello stesso ordine)
             
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& Allocator = allocator_type(),\
                 typename std::enable_if<!std::is_integral<InputIterator>::value >::type* = 0)
                {
                    size_t i = 0;
                    
                    for (InputIterator iter = first; iter != last; iter++)
                        i++;
                    _size = i;
                    _capacity = i;
\
                    InputIterator it = first;
                    _vector = _allocation.allocate(i);

                    for (size_t i = 0; i < _size; i++)
                        _allocation.construct(_vector + i, it++);     
                };
                // Copy constructor (Crea una copia del con ogni elemento in x, nello stesso ordine)
                vector (const vector& x)
                {
                    _size = x._size;
                    _capacity = x._capacity;
                    _vector = _allocation.allocate(_size);
                    for (size_t i = 0; i < _size; i++)
                        _allocation.construct(_vector + i, x._vector[i]);  
                };
                reference   operator[](size_type n){return _vector[n];}
                private:
                        allocator_type                  _allocation;
                        pointer                         _vector;
                        size_type                       _size;
                        size_type                       _capacity;
    
    };


}
#endif