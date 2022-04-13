#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <queue>
#include <iostream>
#include <algorithm>
#include "pair.hpp"

namespace ft
{
    enum Color {RED, BLACK};
        
        template < class value_type>
        struct  Node
        {
            value_type data;
            bool color;
            Node *left, *right, *parent;
        
            // Constructor
            Node(value_type data)
            {
            this->data = data;
            left = right = parent = NULL;
            this->color = RED;
            }
        };




        
        // Class to represent Red-Black Tree
        template <class value, class alloc = std::allocator<Node<value> > >
        class RBTree
        {
                public:
                typedef value                                value_type;
                typedef alloc                                allocator_type;
                typedef typename allocator_type::pointer     pointer;
                typedef typename allocator_type::size_type   size_type;

            public:
                Node <value_type>                       *pt;
                pointer                                 root;
                allocator_type                          _allocation;
                size_type                               _size;
            public:
                // Constructor
                RBTree(const allocator_type& _alloc = allocator_type()):_size(0),
                _allocation(_alloc)
                {root =NULL;};
                public:



                // -------------- FUNZIONI -------------------------
                /*
                    insert inserisce inserisce un nuovo nodo a RBtree,
                    prende come nodo di riferimento root che rappresenta
                    il pointer di allocator_type. Ogni elemento aggiunto
                    si alloca in una posizione specifica tramite l'algoritmo
                    del RBtree. L'elemento in questione e la coppia di valori
                    key-value di pair.
                */
            template < class value_type>
            void levelOrderHelper(Node<value_type>  *root)
                {
                    if (root == NULL)
                        return;
                
                    std::queue<Node<value_type> *> q;
                    q.push(root);
                
                    while (!q.empty())
                    {
                        Node<value_type>  *temp = q.front();
                        std::cout << temp->data.first << "  ";
                        q.pop();
                
                        if (temp->left != NULL)
                            q.push(temp->left);
                
                        if (temp->right != NULL)
                            q.push(temp->right);
                    }
                }

                Node<value_type> *RBinsert(Node<value_type> *root, Node<value_type> *pt)
                {
                    //Se è il primo elemento inserito ritorna pt
                        if (root == NULL)
                            return (pt);
                        //altrimenti se il nuovo nodo è minore mettilo a sinistra
                        if (pt->data < root->data)
                        {
                            root->left = RBinsert(root->left, pt);
                            root->left->parent = root;
                        }
                        // se il nuovo nodo è maggiore posizionalo a destra
                        else if (pt->data > root->data)
                        {
                            root->right = RBinsert(root->right, pt);
                        //  std::cout << root->right->data.first;
                            root->right->parent = root;
                        //  std::cout << root->right->parent->data.first;
                        }
                    // std::cout << root->right->data.first;
                    return (root);
                }

                void rotateRight(Node<value_type> *&root, Node<value_type> *&pt)
                {
                    Node<value_type> *pt_left = pt->left;   // variabile tmp

                    pt->left = pt_left->right; // il figlio sinistro diventa destro

                    if (pt->left != NULL) // se è un figlio sinistro
                        pt->left->parent = pt; // il genitore diventa pt (nuovo nodo)
                    pt_left->parent = pt->parent; // la tmp->padre == il nuovo pt padre
                    if (pt->parent == NULL) // se c'è un padre 
                        root = pt_left; // la root diventa la tmp creata
                    else if (pt == pt->parent->left) // altrimenti se pt è figlio sinistro
                        pt->parent->left = pt_left; // il figlio sinistro diventa la tmp creata
                    else
                        pt->parent->right = pt_left; // altrimenti il figlio destro diventa la tmp creata
                    pt_left->right = pt; // la tmp diventa pt
                    pt->parent = pt_left; // il genitore di pt diventa la tmp
                }

                void rotateLeft(Node<value_type> *&root, Node<value_type> *&pt)
                {
                    Node<value_type> *pt_right = pt->right; // tmp
                    pt->right = pt_right->left; // il figlio destro diventa il figlio sinistro

                    if (pt->right != NULL) // se è presente un figlio destro
                        pt->right->parent = pt; // il padre del figlio destro diventa pt
                    
                    pt_right->parent = pt->parent; // tmp diventa il padre di pt
                    if (pt->parent == NULL) // se non è presente nessun padre di pt
                        root = pt_right; //root diventa la tmp
                    else if (pt == pt->parent->left) // altrimenti se il fratello di pt non è qualcos'altro
                        pt->parent->left = pt_right; // il figlio sinistro diventa destro
                    else
                        pt->parent->right = pt_right; // altrimenti se è qualcos'altro il figlio destro diventa la tmp
                    pt_right->left = pt; //la tmp == pt
                    pt->parent = pt_right; // il padre di pt diviene la nuova tmp

                }

                void fixViolation(Node<value_type> *&root, Node<value_type> *&pt)
                {
                    Node<value_type> *parent_pt = NULL;
                    Node<value_type> *grand_parent_pt = NULL;

                    // fino a quando il nuovo nodo non è root e il colore del nuovo nodo è rosso e
                    // il  colore del padre anche eseguo il 
                    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
                    {
                        parent_pt = pt->parent; // padre
                        grand_parent_pt = pt->parent->parent; // nonno

                        /*
                            Case : A
                            se il padre di pt è il figlio sinistro del nonno di pt
                        */
                        if (parent_pt == grand_parent_pt->left)
                        {
                            //Il nodo zio è il figlio destro del nonno
                            Node<value_type> *uncle_pt = grand_parent_pt->right;

                            /*
                                Case : 1
                                se lo zio di pt è anche esso rosso, si applica il colorflip
                            */
                            if (uncle_pt != NULL && uncle_pt->color == RED)
                            {
                                grand_parent_pt->color = RED;
                                parent_pt->color = BLACK;
                                uncle_pt->color = BLACK;
                                pt = grand_parent_pt;
                            }
                            else
                            {
                                /*
                                Case : 2
                                se pt è il figlio destro di di suo padre
                                si applica la Left-rotation
                                */
                                if (pt == parent_pt->right)
                                {
                                    rotateLeft(root, parent_pt);
                                    pt = parent_pt;
                                    parent_pt = pt->parent;
                                }
                                /*
                                    Case : 3
                                    se pt è il figlio sinistro di suo padre 
                                    si applica la right-rotation
                                */
                                rotateRight (root, grand_parent_pt);
                                std::swap(parent_pt->color, grand_parent_pt->color);
                                pt = parent_pt;

                            }
                            
                        }
                        else
                        {
                            Node<value_type> *uncle_pt = grand_parent_pt->left;
                            /*
                                Case : 1
                                se Lo zio di pt è rosso è richiesto solo il colorflip 
                            */
                            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
                            {
                                grand_parent_pt->color = RED;
                                parent_pt->color = BLACK;
                                uncle_pt->color = BLACK;
                                pt = grand_parent_pt;
                            }
                            else
                            {
                                /*
                                    Case : 2
                                    se pt è il figlio sinistro di suo padre è richiesta
                                    una right-Rotation
                                */
                            if (pt == parent_pt->left)
                            {
                                rotateRight(root, parent_pt);
                                pt = parent_pt;
                                parent_pt = pt->parent;
                            }
                            /*
                                    Case : 3
                                    se pt è il figlio destro di suo padre si applica una Left-Rotation
                            */
                                rotateLeft(root, grand_parent_pt);
                                std::swap(parent_pt->color, grand_parent_pt->color);
                                pt = parent_pt;
                            }
                        }
                    }
                    root->color  = BLACK;
                }

                void inorderHelper(Node<value_type> *root)
                {
                    if (root == NULL)
                        return;
                
                    inorderHelper(root->left);
                    std::cout << root->data.first <<  " " << root->data.second << "  ";
                    inorderHelper(root->right);
                }

                Node<value_type>*   create_node(const value_type &pair_val)
                {
                        Node<value_type> * new_node = _allocation.allocate(1);
                        _allocation.construct(new_node, pair_val);
                        return (new_node);
                }

                void insert(const value_type &pair_val)
                {
                        pt =   create_node(pair_val);

                        //Normale inserzione
                        root = RBinsert(root, pt);
                        
                        // Aggiusta la violazione
                        fixViolation(root, pt);
                        _size++;
                }

                pointer     get_root() {return (this->root);};
                size_type   size(){return (this->_size);};

            void print()
            {
                inorderHelper(root);
            }
        };
}
#endif