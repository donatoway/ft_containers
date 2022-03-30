# FT_CONTAINERS

![alt text](https://res.cloudinary.com/practicaldev/image/fetch/s--DZAyC8cn--/c_imagga_scale,f_auto,fl_progressive,h_420,q_auto,w_1000/https://dev-to-uploads.s3.amazonaws.com/uploads/articles/88cj4x01y7qsn4ok645p.png)
# Every Life Project begins with a Song

https://www.youtube.com/watch?v=X-HsOpW7LIg

# STD::ALLOCATOR

Allocator è il responsabile dell'incapsulazione e della gestione della memoria
Allocator è usato quando vuoi separare l'allocazione e fare la costruzione in 2 step.
Tutti i container STL hanno un parametro allocator type che di default è std::allocator
L'allocator semplicemente usa new e delete per allocare e rilasciare memoria.

    prototype template <class T> class allocator;

FUNCTION :
            address()   : per ottenere l'indirizzo di un oggetto;
            construct() : usato per la costruzione di un oggetto;
            destroy()   : usato per la deallocazione di un oggetto precedentemente allocato;
            max_size()  : questo ritorna l'allocazione massima presente;
            allocate()  : usato per l'allocazione di memoria ;
            deallocate  : usato per la deallocazione di memoria;
Allocator può separare l'allocazione/distruzione dall'inizializzazione e distruzione dei loro elementi

# TYPEDEF AND TYPENAME 
Lo scopo della typedef è quello di assegnare dei nomi alternativi a dei tipi di dato esistenti, 
solitamente a quelli la cui dichiarazione standard è troppo ingombrante, magari confusionale,
oppure per rendere il codice riutilizzabile più facilmente tra un'implementazione e un'altra.

# EXPLICIT 

Explicit nel costruttore indica che quel tipo di costruttore deve essere istanziato solo
richiamando appunto il costruttore  e non potrà essere istanziato assegnando gli argomenti.

    esempio :
    -------------- IMPLICIT CASE CONSTRUCTOR ------------------------
                class A
                {
                    public:
                            A(int i){std::cout << "hai richiamato il costruttore implicito"};
                }

    ------------- EXPLICIT CASE COMNSTRUCTOR ----------------------
                class B
                {
                    public:
                            explicit B(){std::cout << "hai richiamato il costruttore explicit";};
                }

    DIMOSTRAZIONE TEST :
        int main()
        {
            A ClassePrima = 8; //dichiarazione implicita consentita;
            B ClasseSeconda = 8; // return ERROR dichiara implicita non consentita ;
            B ClasseTerza(2); // la classe viene costruita correttamente
        }

# std::Allocator<T>::CONSTRUCT
            prototype void construct (pointer p, const_reference val);
Construct ci permette di creare un nuovo oggetto di tipo value type (con memoria già allocata precedentemente),
sul parametro puntato da p. Il secondo parametro val rappresenta il valore da assegnare all'oggetto 

    Esempio:
            int *integer;
            std::allocator<int>  alloc;

            integer = alloc.allocate(6);
            for (size_t i = 0; i < 6; i++)
                alloc.construct(integer + i, 8);
            
            for (size_t i = 0; i < 6; i++)
                std::cout << integer[i] << " ";

            output will be 8 8 8 8 8 8

# STD::ENABLE_IF

protoptype = template <bool Cond, class T = void> struct enable_if;
il tipo T è attivato  come member type enable_if::type se Cond è true.
Altrimenti, enable_if::type non è definito.
Quetso è molto utile in fase di compilazione quando una particolare consdizione non è
presente 

ESEMPIO:
    // 1. the return type (bool) is only valid if T is an integral type:
    template <class T>
    typename std::enable_if<std::is_integral<T>::value,bool>::type
    is_odd (T i) {return bool(i%2);}

    // 2. the second template argument is only valid if T is an integral type:
    template < class T,
            class = typename std::enable_if<std::is_integral<T>::value>::type>
    bool is_even (T i) {return !bool(i%2);}

        int main()
        {

            short int i = 1;    // code does not compile if type of i is not integral

            std::cout << std::boolalpha;
            std::cout << "i is odd: " << is_odd(i) << std::endl;
            std::cout << "i is even: " << is_even(i) << std::endl;

            return 0;
        }
        //output
        i is odd: true 
        i is even: false

# SFINAE
            "Substitution Failure Is NOt An Error"
Questa regola si applica durante la compilazione dell'overload function templates:
Quando sostituendo una esplicito type per il template esso fallisce, la specializzazione 
viene eliminata dal set di overload invece di causare un errore di compilazione.

La sfinae si serve anche di enable_if ma SFINAE RIMANE UN CONCETTO LOGICO DI SOSTITUZIONE non SINTATTICO

# CONSTEXPR-SPECIFIER
lo specificatore constexpr dichiara che è possiile valutare il valore della funzione o della 
variabile a tempo di compilazione. Tali variabili e funzioni possono essere usati dove solo sono accettati come parametri
nel momento della compilazione.
una  constexpr puo essere chiamata a patto che ci siano dei requisiti.

link : https://en.cppreference.com/w/cpp/language/constexpr

# IS_INTEGRAL
IS_INTEGRAL controlla che il tipo passato come parametro sia di tipo integral. Se è corretto ritorna
true altrimenti ritorna false. Questa struct eredita dalla struct  integral_constant il value booleano
che viene impostato a true o false

        ESEMPIO:
            class A{};
            int main()
            {
                std::cout << std::boolapha;
                std::cout << std::is_integral<A>::value << '\n'; // ritorna false perche A è una classe e quindi non integral

                sd::cout << std::is_integral<char> << "\n"; // ritorna true perchè char è integral 
            
            }

# ITERATOR 

Un iteratore é qualsiasi oggetto che puntando a un elemento in un intervallo di elementi (come un array o un contenitore), ha 
la capacitá di scorrere gli elementi di quell'intervallo utilizzando un insieme di operatori (con almeno l'incremento (++) e 
operatori di dereferenziazione (*)).

 La forma piu usata di iteratore é un puntatore : un puntatore puo puntare agli elementi di un array e puo scorrere attraverso di essi 
 utilizzano l'operatore di incremento (++). Ma sono possibili altri tipi di iteratori. Ad esempio,
 ogni, ogni tipo di contenitore (come un elenco) ha un tipo di iteratore specificoprogettato per scorrere i suooi elementi.

 Nota che mentre un puntatore é una forma di iteratore, non tutti gli iteratori hanno la stessa funzionalità dei puntatori;
 a seconda delle proprietà supportate dagli iteratori, sono classificati in cinque diverse categorie:

 Input  <---- Forward <---- Bidirectional <---- Random Access
 Output

# REVERSE ITERATOR
 reverse iterator è un adatttatore iteratore che inverte la direzione di un determinato iteratore, che deve essere almeno un 
 Legacy Bidirezionale iterator o un modello bidirezionale iterator. an altre parole, quando viene fornito con un iteratore 
 bidirezionale std::reverse_iterator produce un nuovo iteratore che si sposta dalla fine della sequenza definita dall'iteratore
 bidirezionale sottostante.

 per u iteratore invers r costruito da un iteratore i, la &*r == &*(i - 1) è sempre ver (purche r sia dereferenziabile);
 quindi un iteratore inverso costruito da un iteratore one-pas the end dereferenziabile all'ultimo element di una sequenza.

 Questo è l'iteratore restituito dalle funzioni membro rbegin() e rend() dei contenitori della libreria standard.
   
 # Map
     
Map è un Container associativo che salva gli elementi con una combinazione Chiave - Valore, seguendo un ordine specifico.
In Map La chiave è usata generalmente per riordinare la lista di elememti;
Map è piu lento rispetto a unordered_map , ma ti permette l'íterazione direttamente in base al loro ordine.
Si puo accedere ai valori direttamente attraverso la loro chiave corrispondente, quindi con le brackets operator[]

        Esempio di Utilizzo di Map:

            map<string, string> uomo;
    
            uomo.insert(pair<string, string>("carlone", "cuoco"));

            map<string, string>::iterator itr;

            for (itr = uomo.begin() ;itr != uomo.end();itr++)
                cout << itr->first << "-" << itr->second <<  endl;

 # lezione su map :
https://www.youtube.com/watch?v=aEgG4pidcKU

# Red and Black tree

Il RBTree segue 6 regole proncipali

- Ogni Nodo è rosso o nero

- La Root è sempre nera

- Ogni inserzione è sempre Rossa

- Ogni Path dalla Root al Leaf ha lo stesso numeo di neri

- Nessun Path puó avere 2 nodi rossi consecutivi

- NULL è sempre nero 

Per aggiustare il nostro albero quando si verificano situazioni di violazione, ovvero che le regole sopra citate non vengono rispettate utilizziamo :


                Rebalance: 
                    se abbiamo nel nodo in cui si verifica la violazione
                    abbiamo uno zio Nero :  applichiamo Black Aunt Rotate : Bar

                    se abbiamo nel nodo in cui si verifica la violazione
                    abbiamo uno zio Rosso : Red Aunt ColorFlip : RAC
                    
                Dopo Una Rotation il padre          dopo un ColorFlip il padre è rosso
                è black e i figli sono rossi        e i figli sono neri 
                        BLACK                               RED
                        /   \                              /    \
                    RED        RED                      BLACK   BLACK

Ci sono 4 tipi di rotazione: Left-Rotation, Right-Rotation, Left-Right-Rotation, Right-left-Rotation.

                /
               /
Se in Balance abbiamo nel Nonno, left-child e left-subtree : applichiamo Right-Rotation.

                \
                 \
Se in Balance abbiamo nel Nonno, right-child e right-subtree : applichiamo Left-Rotation.

                /
                \
Se in Balance abbiamo nel Nonno, left-child e right-subtree : applichiamo Left-Right-Rotation.

                    \
                    /               
Se in Balance abbiamo nel Nonno, right-child e left-subtree : applichiamo Right-Left-Rotation.
