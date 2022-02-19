#include "vector.hpp"
#include "iterators.hpp"
#include <iterator>
#include <vector>
#include <iostream>
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
//provare a istanziare i costruttori
int main()
{
  
  //empty default constructor
  ft::vector<int> a;

  //fill constructor 
  std::cout << GREEN"FILL CONSTRUCTOR"RESET << "\n";
  ft::vector<int> b(5,100);
  for (size_t i = 0; i < 5; i++)
    std::cout << b[i] << "\n";

  //iterator constructor
  std::cout << GREEN"ITERATOR CONSTRUCTOR"RESET << "\n";
  std::vector<int> c;
  for (size_t i = 0; i < 9; i++)
    c.push_back(i);
  ft::vector<int>   d(c.begin(),c.end());
  for (size_t i = 0; i < 9; i++)
    std::cout << d[i] << "\n";

  //copy constructor
  std::cout << GREEN"COPY CONSTRUCTOR"RESET << "\n";
  ft::vector<int>   e(b);
  for (size_t i = 0; i < 5; i++)
    std::cout << e[i] << "\n";
  //assign=operator 
  std::cout << GREEN"ASSGN-OPERATOR CONSTRUCTOR"RESET << "\n";
  ft::vector<int> foo(5,70);
  ft::vector<int> bar(6,1);
  bar = foo;
  for (size_t i = 0; i < 5; i++)
    std::cout << bar[i] << "\n";

  //TEST ITERATOR E REVERSE_ITERATOR
  std::cout << GREEN"TEST ITERATOR : "RESET << "\n";
  int array[9] = {1,2,3,4,5,6,7,8,9};
  ft::vector<int>                   TestIterator(array, array + 9);
  ft::vector<int>::iterator         it;
  for (it = TestIterator.begin(); it != TestIterator.end(); it++)
    std::cout << *it << " ";
  
  std::cout << GREEN"\nTEST REVERSE ITERATOR : "RESET << "\n";
  ft::vector<int>::reverse_iterator   rev_it;
  for (rev_it = TestIterator.rbegin(); rev_it != TestIterator.rend(); rev_it++)
    std::cout << *rev_it << " ";

  //contnuare con capacitty
  //resize
  std::cout << GREEN"\nTEST RESIZE : "RESET << "\n";
  int ar[5] = {1,2,3,4,5};
  ft::vector<int>     res(ar, ar + 5);
  ft::vector<int>::iterator it2;
  std::cout << "before  : ";
  for (it2 = res.begin(); it2 != res.end(); it2++)
    std::cout << *it2 << " ";
  std::cout << "\nafter    :";
  res.resize(10,55);
  for (it2 = res.begin(); it2 != res.end(); it2++)
    std::cout << *it2 << " ";
  res.resize(2);
  std::cout << "\nafter less: ";
  for (it2 = res.begin(); it2 != res.end(); it2++)
    std::cout << *it2 << " ";

  //RESIZE E RESERVE FATTI CONTINUARE CON LE ALTRE FUNZIONI
  return 0;
}