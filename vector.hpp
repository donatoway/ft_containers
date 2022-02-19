#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include "iterators.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

namespace ft
{
    template < class T, class alloc = std::allocator<T> >
    class vector
    {
        public:
                typedef T                                               value_type;
                typedef alloc                                           allocator_type;
                typedef typename allocator_type::size_type              size_type;
               // typedef typename std::ptrdiff_t                         difference_type;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::const_reference        const_reference;
                typedef typename allocator_type::pointer                pointer;
                typedef typename allocator_type::const_pointer          const_pointer;
                typedef typename ft::vector_iterator<pointer>           iterator;
                typedef typename ft::vector_iterator<const_pointer>     const_iterator;
                typedef typename ft::const_reverse_iterator<const_iterator>   const_reverse_iterator;
                typedef typename ft::reverse_iterator<iterator>         reverse_iterator;

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
                 typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
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
                        _allocation.construct(_vector + i, *it++);
                };
                // Copy constructor (Crea una copia con ogni elemento in x, nello stesso ordine)
                vector (const vector& x)
                {
                    _size = x._size;
                    _capacity = x._capacity;
                    _vector = _allocation.allocate(_size);
                    for (size_t i = 0; i < _size; i++)
                        _allocation.construct(_vector + i, x._vector[i]);
                };
                // Distruttore
                ~vector()
                {
                    if (_size)
                        _allocation.deallocate(_vector, _size);
                };
                vector& operator= (const vector& x)
                {
                    if (_capacity)
                        _allocation.deallocate(_vector, _capacity);
                    _size = x._size;
                    _capacity = x._capacity;
                    _allocation = x._allocation;
                    if (_size)
                        _allocation.allocate(_size);
                    for (size_t i = 0; i < _size; i++)
                        _allocation.construct(_vector + i, x._vector[i]);
                    return (*this);
                }

                //FUNZIONI
                //begin
                //------------------- ITERATOR -----------------------------
                iterator        begin(){return iterator(_vector);};
                const_iterator  begin()const {return const_iterator(_vector);};
                iterator        end() {return iterator(_vector + _size);};
                const_iterator  end() const {return const_iterator(_vector);};

                reverse_iterator        rbegin(){return reverse_iterator(end());};
                const_reverse_iterator  rbegin()const{return const_reverse_iterator(end());};
                reverse_iterator        rend(){return reverse_iterator(begin());};
                const_reverse_iterator  rend()const{return const_reverse_iterator(end);};


                //-------------------- CAPACITY ------------------------------
                size_type size() const
                {
                    return (this->_size);
                };

                size_type max_size() const
                {
                    return (_allocation.max_size());
                };

                void reserve (size_type n)
                {
                    //se n è maggiore aumenta la _capacity del vettore
                    if (n > _capacity)
                    {
                        pointer temp = _allocation.allocate(n);
                        for (size_t i = 0; i < _size; i++)
                            temp[i] = _vector[i];
                        _allocation.deallocate(_vector, _capacity);
                        _vector = temp;
                    };
                };

                void resize (size_type n, value_type val = value_type())
                {
                    //se n è maggiore della capacità del vettore alloco memoria extra
                    if (n > _capacity)
                        reserve(n);
                    //nel caso n sia minore vado a cancellare tutto cio che
                    //c'e dopo l'n esimo elemento
                    if (n < _size)
                    {
                        for (size_t tmp = n; tmp < _size; tmp++)
                            _allocation.destroy(_vector + tmp);
                        _size = n;
                    };
                    //se n è maggiore tutto cio che viene dopo _size è 0 oppure val
                    if (n >= _size)
                    {
                        if (!val)
                            val = 0;
                        for (size_t i = _size; i < n; i++)
                            _vector[i] = val; 
                        _size = n;
                    }
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