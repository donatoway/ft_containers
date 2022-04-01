#ifndef RBTREE_HPP
#define RBTREE_HPP

#define RED 0
#define BLACK 1
/*
    In RedBlackTree utilizziamo 2 modi per Ribilanciare l'albero, Colorflip e Rotazione.
    Se il colorflip non puo essere applicato allora applichiamo il rotate


*/

namespace ft
{
    /*
        L'algoritmo RBtree ordina i dati in modo binario, quindi la
        La classe di RBtree possiede i dati relativi agli oggetti (nodi), e le funzioni 
        per capire dove salvare gli oggetti (nodi)
    */

   template <class value_type>
   struct node
   {
        value_type data;
        bool color;
        node *left, *right, *parent;

        // Costruttore
        Node(value_type data)
        {
            this->data = data;
            left = right = parent = NULL;
            this->color = RED;
        }
   };

 //in map implementiamo pair e lo passiamo come value_type
    template<class value_type>
    class RBTree
    {
        public:
                node *root;
        protected:
               // void rotateLeft(Node *&, Node *&);
               // void rotateRight(Node *&, Node *&);
               // void fixViolation(Node *&, Node *&);
        public:
                RBTree(){root = NULL;};
                void insert (const value_type &val)
                {
                    node *new_node<value_type> = new node<value_type>(val); 
                }
    };
};




#endif