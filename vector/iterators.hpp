#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>

/*
    ITERATOR:
    Questa classe base fornisce solo alcuni tipi di membri, che di fatto non devono essere 
    presenti in alcun tipo di iteratore (i tipi di iteratore non hanno requisiti specifici 
    per i membri), ma potrebbero essere utili, poiché definiscono i membri necessari per 
    il modello di classe iterator_traits predefinito per generare automaticamente l'istanza 
    appropriata (e tale istanziazione deve essere valida per tutti i tipi di iteratore).

    ITERATOR_TRAITS
    Traits class definisce le proprieta di un iteratore .

    Gli algritmi standard determinano alcune proprieta degli iteratori passati
    loro e l'intervallo che rappresentano utilizzando i membri dell'istanza iterator_traits
    corrispondente 

    Per ogni tipo di iteratore, deve essere definita una corrispondente specializzazione del modello di classe
    iterato_traits, con almeno i seguenti tipi di membri definiti.
    difference_type
    value_type
    pointer
    reference
    iterator_category
*/




namespace ft
{
    //iterator tag
    struct input_iterator_tag {};

    struct output_iterator_tag {};

    struct forward_iterator_tag   : public input_iterator_tag {};

    struct bidirectional_iterator_tag  : public forward_iterator_tag {};

    struct random_access_iterator_tag  : public bidirectional_iterator_tag {};

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category	iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef     ptrdiff_t                       difference_type;
        typedef     T                               value_type;
        typedef     T*                              pointer;
        typedef     T&                              reference;
        typedef     ft::random_access_iterator_tag  iterator_category;                     
    };
//------------------ REVERSE ITERATOR --------------------------
    template <class Iter>
    class reverse_iterator : public iterator<typename iterator_traits<Iter>::iterator_category, typename iterator_traits<Iter>::value_type, typename iterator_traits<Iter>::difference_type, typename iterator_traits<Iter>::pointer, typename iterator_traits<Iter>::reference>
    {
        protected:
                    Iter current;
        public:
                //MEMBER TYPE
                typedef Iter                                                    iterator_type;
                typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
                typedef typename ft::iterator_traits<Iter>::value_type          value_type;
                typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
                typedef typename ft::iterator_traits<Iter>::pointer             pointer;
                typedef typename ft::iterator_traits<Iter>::reference           reference;
                
                //COSTRUTTORI
                //il costruttore di default è value-inizialized.
                reverse_iterator():current(){};
                //l'iteratore viene inizializzato con x
                reverse_iterator( iterator_type x ) : current(x){};
                //l'iteratore è inizializzato con quello di altri. Questo overload lo risolve solo se U non è dello stesso tipo
                //di iter 
                template< class U > 
                reverse_iterator(const reverse_iterator<U>& other ) : current(other.base()) {};
                template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u) { current = u.base(); return *this; }
                
                //FUNZIONI 
                Iter                base() const {return current;};
                // *,-> ritornano una referenza  o un puntatore all'elemento precedenre di it
                reference           operator  *() const {Iter tmp = current; return *--tmp;};
                pointer             operator->() const {return &(operator*());};
                //operator ++,+,+=,--,-,-=
                //le operazioni di increment e decrement funzionano al contrario dato che è un reverse mode
                reverse_iterator&   operator++(){--current; return *this;};
                reverse_iterator    operator++(int){reverse_iterator tmp = *this; --current; return tmp;};
                reverse_iterator&   operator--(){++current;return *this;};
                reverse_iterator    operator--(int){reverse_iterator tmp = *this; ++current; return tmp;};
                reverse_iterator    operator+ (difference_type n)const {return reverse_iterator(current - n); };
                reverse_iterator&   operator+= (difference_type n){current -= n; return *this;}
                reverse_iterator    operator- (difference_type n)const {return reverse_iterator(current + n);};
                reverse_iterator&   operator-= (difference_type n){current += n; return *this;};
                reference           operator[](difference_type n) const {return *(*this + n);};
    };
    template <class Iter>
    class const_reverse_iterator  : public iterator < typename iterator_traits<Iter>::iterator_category, typename iterator_traits<Iter>::value_type, typename iterator_traits<Iter>::difference_type, typename iterator_traits<Iter>::pointer, typename iterator_traits<Iter>::reference>
    {
        protected:
                Iter current;
        public:
                typedef Iter                                                iterator_type;
                typedef typename iterator_traits<Iter>::difference_type     difference_type;
                typedef typename iterator_traits<Iter>::value_type          value_type;
                typedef typename iterator_traits<Iter>::reference           reference;
                typedef typename iterator_traits<Iter>::pointer             pointer;

                //COSTRUTTORI
                const_reverse_iterator () : current() {};
                const_reverse_iterator (value_type* p) {current = Iter(p);};
                const_reverse_iterator( const iterator_type& x) {current = x;};
                template< class U >
		        const_reverse_iterator( const const_reverse_iterator<U>& other ) { *this = other; };
                template< class U >
		        const_reverse_iterator( const reverse_iterator<U>& other ) { *this = other;};

                //FUNZIONI
                Iter                    get_current()const {return (current);};
                Iter                    base() const {return Iter(current);};
                template< class U > 
                const_reverse_iterator& operator=( const const_reverse_iterator<U>& other ){current = other.get_current(); return *this;};
                template< class U > 
                const_reverse_iterator& operator=( const reverse_iterator<U>& other ) {current = other.get_current(); return *this;};
                value_type*               operator*(){Iter tmp = current; return *--tmp;};
                value_type*              operator->(){Iter tmp = current; return tmp.operator->();};
                reference   operator[]( difference_type n )const{return *(this + n);};              
                const_reverse_iterator&     operator++(){--current; return this;};
                const_reverse_iterator      operator--(){++current; return this;};
                const_reverse_iterator      operator++(int){const_reverse_iterator temp = *this; --current; return temp;};
                const_reverse_iterator      operator--(int){const_reverse_iterator temp = *this; ++current; return temp;};
                const_reverse_iterator      operator+(difference_type n) const { return const_reverse_iterator(current - (n));};
                const_reverse_iterator      operator-(difference_type n) const { return const_reverse_iterator (current + (n));};
                const_reverse_iterator&     operator+=(difference_type n) {current -= (n); return *this;};
                const_reverse_iterator&     operator-=(difference_type n) {current += (n); return *this;};
    };

    // bool operator su reverse_iterator
    template< class Iterator1, class Iterator2>
    bool operator ==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    };

    template <class Iterator1, class Iterator2>
    bool operator !=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator < (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator > (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator <= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator1, class Iterator2>
    bool operator >= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iter>
    reverse_iterator<Iter>
    operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return (it.base() - n);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type
    operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() -  rhs.base());
    };

    //bool operator su const_reverse_iterator
    template    <class Iterator1, class Iterator2>
    bool operator == (const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator <Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    };

    template    <class Iterator1, class Iterator2>
    bool operator != (const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator <Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    };

    template    <class Iterator1, class Iterator2>
    bool operator <(const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator <Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    };

    template    <class Iterator1, class Iterator2>
    bool operator >(const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator <Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template    <class Iterator1, class Iterator2>
    bool operator >= (const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator<Iterator2>& rhs)
    { 
        return lhs.base() <= rhs.base(); 
    };

    template    <class Iterator1, class Iterator2>
    bool operator <= (const const_reverse_iterator<Iterator1>& lhs, const const_reverse_iterator<Iterator2>& rhs)
    { 
        return lhs.base() >= rhs.base(); 
    };

    template <class Iterator>
    const_reverse_iterator<Iterator> operator + (typename const_reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
    {
        return (it.base() - n);
    };

    template <class Iterator1, class Iterator2>
    typename const_reverse_iterator<Iterator1>::difference_type
        operator - (const_reverse_iterator<Iterator1>& lhs, const_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

//------------------------ ITERATOR --------------------------------

template <class Iterator>
class vector_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, typename iterator_traits<Iterator>::value_type,
                                        typename iterator_traits<Iterator>::difference_type, typename iterator_traits<Iterator>::pointer,
                                        typename iterator_traits<Iterator>::reference>
{
    private:
            Iterator current;
    public:
            typedef Iterator                                                    iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category       iterator_category;
            typedef typename iterator_traits<Iterator>::difference_type         difference_type;
            typedef typename iterator_traits<Iterator>::reference               reference;
            typedef typename iterator_traits<Iterator>::pointer                 pointer;
            
            //Costruttori
            vector_iterator() : current(nullptr){};
            explicit vector_iterator(Iterator it) : current(it){};
            template <class T>
            explicit vector_iterator(const vector_iterator<T>& obj) : current(obj.base()){};

            //Funzioni
            template <class V>
            vector_iterator     operator=(const vector_iterator<V> &obj) {current = obj.base(); return *this;};
            Iterator            base()const{return (current);};
            reference           operator*() const {return *current;};
            pointer             operator->() const {return current;};
            vector_iterator&    operator++() {++current; return *this;};
            vector_iterator&    operator--() {--current; return *this;};
            vector_iterator     operator++(int) {vector_iterator temp = *this; ++current; return temp;};
            vector_iterator     operator--(int) {vector_iterator temp = *this; --current; return temp;};
            vector_iterator     operator+ (difference_type n) const {return vector_iterator(current + n);};
            vector_iterator     operator- (difference_type n) const {return vector_iterator(current -n);};
            vector_iterator     operator+= (difference_type n) const {current += n; return *this;};
            vector_iterator     operator-= (difference_type n) const {current -= n; return *this;};
            reference           operator[] (difference_type n) const {return  *this + n;};
};                 
    template <class Iterator1, class Iterator2>
            bool operator == (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs){return (lhs.base() == rhs.base());};
            template <class Iterator1, class Iterator2>
            bool operator != (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return (lhs.base() != rhs.base());};
            template <class Iterator1, class Iterator2>
            bool operator < (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return (lhs.base() < rhs.base()); };
            template <class Iterator1, class Iterator2>
            bool operator > (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return (lhs.base() > rhs.base());};
            template <class Iterator1, class Iterator2>
            bool operator <= (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return (lhs.base() <= rhs.base());};
            template <class Iterator1, class Iterator2>
            bool operator >= (const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return (lhs.base() >= rhs.base());};
            template <class Iterator>
            vector_iterator<Iterator> operator + (typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& obj) {return (vector_iterator<Iterator>(obj.base() + n));};
            template <class Iterator1, class Iterator2>
            typename vector_iterator<Iterator1>::difference_type
            operator -(const vector_iterator<Iterator1>& lhs, const vector_iterator<Iterator2>& rhs) {return lhs.base() - rhs.base();};
};
#endif