#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../map/map.hpp"
#include <cstring>
#include "iterators.hpp"
#include "vector.hpp"

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
                typedef typename std::ptrdiff_t                         difference_type;
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
                _allocation(Allocator), _vector(nullptr), _capacity(0)
                {
                    _size = 0;
                    _vector = _allocation.allocate(0);
                };

                //Fill Constructor (costruisce un vettore con n elementi, ed ogni elemento ?? una copia di val)

                explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& Allocator = allocator_type()):_allocation(Allocator), _vector(0),_capacity(0)
                {
                    _size = n;
                    _capacity = n * 2;
                    _vector = _allocation.allocate(_capacity);
                    if (n > 0)
                    {
                        for (size_t i = 0; i < n; i++)
                            _allocation.construct(&_vector[i], val);
                    }
                };
                //Range Constructor (costruisce un vettore con tanti elementi quanto il range [first last] , con
                    //ogni elemento costruito dal suo corrispondente elemento in quella posizione del range, nello stesso ordine)

                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& Allocator = allocator_type(),\
                 typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0):_allocation(Allocator)
                {
                    size_t i = 0;
                    for (InputIterator iter = first; iter != last; iter++)
                        i++;
                    _size = i;
                    _capacity = i*2;
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
                    if (_capacity != 0 || _vector != NULL)
				        _allocation.deallocate(_vector, _capacity);
                };
                vector& operator= (const vector& x)
                {
                    if (_capacity > 0 && _size > 0)
                        _allocation.deallocate(_vector, _capacity);
                    _size = x._size;
                    _capacity = x._capacity;
                    _allocation = x._allocation;
                    for (size_t i = 0; i < _size; i++)
                        _allocation.construct(_vector + i, x._vector[i]);
                    return (*this);
                }

                //FUNZIONI
                
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

                void reserve( size_type n )
                {
                    if (n > _capacity && _vector != nullptr)
                    {
                        pointer tmp = NULL;
                        tmp = _allocation.allocate(n);
                        for (size_t i = 0; i < _size; i++)
                                _allocation.construct((tmp + i), _vector[i]);
                        _allocation.deallocate(_vector, _capacity);
                        _vector = _allocation.allocate(n);
                        for (size_t i = 0; i < _size; i++)
                                _allocation.construct((_vector + i), tmp[i]);
                        _capacity = n;
                        _allocation.deallocate(tmp, n);
                    }
                    else if (_vector == nullptr)
                    {
                        _capacity = n;
                        _vector = _allocation.allocate(_capacity);
                    }
                }
                
                void resize (size_type n, value_type val = value_type())
                {
                    //se n ?? maggiore della capacit?? del vettore alloco memoria extra
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
                    //se n ?? maggiore tutto cio che viene dopo _size ?? 0 oppure val
                    if (n >= _size)
                    {
                        if (!val)
                            val = 0;
                        for (size_t i = _size; i < n; i++)
                            _vector[i] = val; 
                        _size = n;
                    }
                };

                bool empty() const
                {
                    //controlla che il container non ha elementi
                    //ritorna true se non ha elementi altrimenti false

                    if (_size == 0) return true;
                    return false;
                }

                size_type capacity() const
                {
                    return (_capacity);
                };

        //------------- ELEMENT ACCESS ---------------------------
                reference   operator[](size_type n){return _vector[n];}
                reference   operator[](size_type n)const {return _vector[n];}
                reference at( size_type pos )
                {
                    if (pos < 0 || pos > _size)
                        throw std::out_of_range("out of range");
                    return (_vector[pos]);
                    //ritorna una referenza a una specifica posizione pos
                };
                const_reference at( size_type pos )const
                {
                    if (pos < 0 || pos > _size)
                        throw std::out_of_range("out of range");
                    return (_vector[pos]);
                    //ritorna una referenza a una specifica posizione pos
                };
                reference front() {return (_vector[0]);};
                const_reference front () const{return (_vector[0]);};
                reference back() {return *(end() - 1);};
                const_reference back()const {return *(end() - 1 );};
        //------------------------ MODIFIERS --------------------------------

            void clear(){_size = 0;};
            // INSERT: (2 parametri) inserisce un elemento in una specifica posizione
            // riallocazione se la nuova size ?? maggiore della vecchia capacity
            // tutti gli iteratori e referenze sono invalidate
            // tuttavia solo gli iteratori e referenze prima del punto di inserzione
            // rimangono validi 
            iterator insert( iterator pos, const T& value )
            {
                difference_type index = pos - begin();
                
                insert(pos, 1, value);
                return iterator(&_vector[index]);
            };
            //INSERT: (3 parametri) inserisce un'ammontare di volte,
            //il valore passato come terzo argomento
            void insert( iterator pos, size_type count, const T& value )
            {
                iterator    it;
                size_t      i = 0;
                size_t      x = 0;
                for (it = begin(); it != pos; it++)
                    i++;
                if (i > _size)
                    _size = i;
                _size += count;
                if (_capacity < _size)
                    reserve(_size * 2);
                x = i;
                size_t nsize = _size - 1;
                while (nsize  >= (i + count))
                {
                    _vector[nsize] = _vector[nsize - count];
                    nsize--;
                };
                while (count--)
                    _vector[i++] = value;
            };

            //INSERT : (3 parametri Template) inserisce un range di elementi
            // da first a last, alla posizione pos
            template< class InputIt >
            void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0 )
            {
                iterator it;
                InputIt it2;
                size_t  i = 0;
                size_t  x;
                size_t  count = 0;
                for (it = begin(); it != pos; ++it)
                    i++;
                for (it2 = first; it2 != last; ++it2)
                    count++;
                if (i > _size)
                    _size = i;
                 _size += count;
                if (_capacity < _size)
                    reserve(_size * 2);
                x = i;
                size_t nsize = _size - 1;
                while (nsize  >= (count + i))
                {
                    _vector[nsize] = _vector[nsize - count];
                    nsize--;
                };
                while (count--)
                    _vector[i++] = *first++;      
            };

            //ERASE (1 parametro): cancella l'elemente presente alla posizione pos
            //          restituisce l'iterator end()
            iterator erase( iterator pos )
            {
                iterator it;
                size_t i = 0;
                for (it = begin(); it != pos; it++)
                    i++;
                for (; i + 1 < _size ; i++)
                {
                    _vector[i] = _vector[i + 1];
                }
                 while (it != end())
                    it++;
                _size-= 1;
                return it;      
            };
            //ERASE (2parametri): rimuove gli elementi nel range first - last
            iterator erase( iterator first, iterator last )
            {
                iterator it;
                size_t  count = 0;
                size_t  i = 0;
                for (it = first; it < last; it++)
                    count++;
                for (it = begin(); it != first; it++)
                    i++;
                size_t tmp = count;
                while (count--)
                {
                    _vector[i] = _vector[i + tmp];
                    i++;
                }
                _size -= tmp;
                while (it != end())
                    it++;
                return it;          
            };
            //PUSH_BACK : aggiunge un elemento alla coda del vettore
            void push_back( const T& value )
            {
                if ((_size + 1) > _capacity)
                    reserve((_size + 1)*2);
                _size += 1;
                _allocation.construct((_vector + _size - 1), value);
			    _vector[_size - 1] = value; 
            };
            //POP_BACK : rimuove l'ultimo elemento
            void pop_back()
            {
                iterator it =begin();
                while (it != end())
                    ++it;
                erase(it);
            };
            //SWAP : Scambia il contenuto del conteiner con quello di altri
            //       Non richiama nessun copy, move o swap sugli elementi
            void swap( vector& other )
            {
                pointer vector_tmp = other._vector;
                allocator_type _allocation_tmp = other._allocation;
                size_type       size_tmp =other._size;
                size_type       _capacity_tmp =other. _capacity;

                other._vector = this->_vector;
                other._allocation = this->_allocation;
                other._size = this->size();
                other._capacity = this->_capacity;

                this->_vector = vector_tmp;
                this->_allocation = _allocation_tmp;
                this->_size = size_tmp;
                this->_capacity = _capacity_tmp;
            };
                private:
                        allocator_type                  _allocation;
                        pointer                         _vector;
                        size_type                       _size;
                        size_type                       _capacity;
                public:
            
    };
            template< class T, class Alloc >
            bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
            {
                if(lhs.size() != rhs.size())
                    return(false);
                for (size_t i = 0; i < lhs.size(); i++)
                    if(lhs[i] != rhs[i])
                        return(false);
                return(true);
            }
            template< class T, class Alloc >
             bool operator!=(const  vector<T, Alloc>& lhs, const  vector<T, Alloc>& rhs ){return !(lhs == rhs);};
            template< class T, class Alloc >
             bool operator<( const  vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
            {
                if (lhs.size() < rhs.size())
                    return (true);
                return (ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
            }

            template< class T, class Alloc >
             bool operator<=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
            {
                return (!(lhs > rhs));
            }

            template< class T, class Alloc >
            bool operator>( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs )
            {
                if (lhs.size() > rhs.size())
                    return (true);
                return (ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end()));
            }

            template< class T, class Alloc >
            bool operator>=( const vector<T, Alloc>& lhs, const  vector<T, Alloc>& rhs )
            {
                return (!(lhs < rhs));
            }
};

#endif