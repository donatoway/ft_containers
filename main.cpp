#include <iostream>
#include "vector.hpp"
#include <memory>
#include <vector>
#include <type_traits>

/*
 1) In questo progetto reimplementerai i vari tipi di Conteiners
    Per ogni containers metti dentro la sua class file .hpp
    Il namespace sarà sempre ft::
    Ogni vecchia feature fino a c++98 sarà implementata 

 2) - Implementa i seguenti containers e metti dentro i relativi file .hpp
    - Metterai dentro un main per testare tutto
    - Produrrai un binario uno con i tuoi containers e l'altro con quello
      della libreria stl.
 3) - Compara l'output e il tempo di esecuzione (può essere al massimo 20 volte piu lento)
    - Member function, Non member Function e overloads sono richiesti
    - Rispetta i nomi e i dettagli.
    - Dovresti usare STD::ALLOCATOR
    - Devi giustificare la tua struttura dati interna per ogni contenitore. 
    - se il conteiner ha un iterator system, dovrai implementarlo
        iterators_traits, reverse_iterator, enable_if, is_integral,
        equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented.
    - You can use https://www.cplusplus.com/ and https://cppreference.com/ as references.
    - Non potrai implementare più public function di quelle presenti nel container.
    - ogni cosa sarà private o protected. Ogni public function dovra essere giustificata
    - Per le Non-Member overloads. Friends è accettata . Ogni uso di Friend sara
      giustificato
    
    [CONTAINERS]
    Dovrai inserire i Seguenti containers
    -   Vector
    -   Map
    -   Stack

    -   Per il tuo Vector:: non c'è bisogno di reimplementare vector<bool>
    -   stack userà il tuo Vector come contenitore sottostante. Questo dovrà essere 
        ancora compatibile con gli altri containers come STL
    -   STL CONTAINER è Proibito
    -   è concesso usare STL library


*/
// se la condizione booleana è vera viene definito i nuovo typedef T type
/*
namespace giga
{
  template<bool Cond, class T = void>
  struct enable_if {};

  template<class T> 
  struct enable_if<true, T> 
  { typedef T type; };

// nel caso in cui il parametro passto sia false non lo fa neanche istanziare
//e lo segnala coe errore perche tentiamo di accedere a type ma type non è stato creato
template < class T, class = typename giga::enable_if<std::is_void<T>::value>::type>
void is_even (T i)
{
  std::cout << "sono stato istanzito"<< std::endl;
}
*/
class A {};
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

int main()
{
  //creare enable_if nel ft namespace, una volta completato usare tutto
  //cio per completare i costruttori 
}