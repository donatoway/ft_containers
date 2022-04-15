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

            Node *uncle()
            {
                // Se non ci sono genitori e nonni non ci sono zii
                if (parent == NULL or parent->parent == NULL)
                    return NULL;
                //se lo zio non e a sinistra e a destra 
                if (parent->isOnLeft())
                       return parent->parent->right;
                else
                    return parent->parent->left;
            }
            //controlla che il nodo è figlio sinistro
            bool isOnLeft() { return this == parent->left; }

            // ritorna un puntatore alla sorella
            Node *sibling()
            {
                // se non ci sono genitori non ci sono sorelle
                if (parent == NULL)
                    return NULL;
            
                if (isOnLeft())
                    return parent->right;
                return parent->left;
            }
            // Muove il nodo giu e muove il nodo nel suo posto
            void moveDown(Node *nParent)
            {
                if (parent != NULL)
                {
                    if (isOnLeft()) 
                        parent->left = nParent;
                    else
                        parent->right = nParent;
                }
                nParent->parent = parent;
                parent = nParent;
            }

            bool hasRedChild()
            {
                return (left != NULL && left->color == RED) ||
                    (right != NULL && right->color == RED);
            }
        };




        
        // Class to represent Red-Black Tree
        template <class value, class k, class alloc = std::allocator<Node<value> > >
        class RBTree
        {
                public:
                typedef value                                value_type;
                typedef k                                    key_type;
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
            
            void leftRotate(Node<value_type> *x)
            {
                // il nuovo genitore sarà il figlio destro
                Node<value_type> *nParent = x->right;
            
                // se x è la root, la root sara nparent(figlio Destro)
                if (x == root)
                    root = nParent;
                x->moveDown(nParent);
                // Connetti x con il nuovo figlio sinistro di nParent
                x->right = nParent->left;

                //connetti il nuovo genitore del figlio sinistro  con il nodo
                if (nParent->left != NULL)
                    nParent->left->parent = x;
                // connetti il nuovo genitore con x
                nParent->left = x;
            }
            
            void rightRotate(Node<value_type> *x)
            {
                // new parent will be node's left child
                // il nuovo genitore sarà il figlio sinistro
                Node<value_type> *nParent = x->left;
            
                // update root if current node is root
                // se x == root allora la root sarà il nuovo nParent(figlioSinistro)
                if (x == root)
                    root = nParent;
                x->moveDown(nParent);
                // connetti x con il nuovo genitore di destra
                x->left = nParent->right;
                // connetti il nuovo genitore di destra con il nodo 
                // se non è null
                if (nParent->right != NULL)
                    nParent->right->parent = x;
                // connetti il nuovo genitore con x
                nParent->right = x;
            }
            
            void swapColors(Node<value_type> *x1, Node<value_type> *x2)
            {
                bool temp;
                temp = x1->color;
                x1->color = x2->color;
                x2->color = temp;
            }
            
            void swapValues(Node<value_type> *u, Node<value_type> *v)
            {
                Node<value_type> *temp;
                temp->data = u->data;
                u->data = v->data;
                v->data = temp->data;
            }
            
            // fix red red at given node
            void fixRedRed(Node<value_type> *x)
            {
                // se la root è x allora x = BLACK
                if (x == root)
                {
                    x->color = BLACK;
                    return;
                }
            
                // inizializza genitore, nonno e zio
                Node<value_type> *parent = x->parent, *grandparent = parent->parent,
                    *uncle = x->uncle();
            
                if (parent->color != BLACK)
                {
                    if (uncle != NULL && uncle->color == RED)
                    {
                        // se lo zio è RED, usa il colorflip ricorsivo
                        parent->color = BLACK;
                        uncle->color = BLACK;
                        grandparent->color = RED;
                        fixRedRed(grandparent);
                    }
                    else
                    {
                        //Altimenti utilizza i Rotate
                        if (parent->isOnLeft())
                        {
                            if (x->isOnLeft()) // per il left-right
                                swapColors(parent, grandparent);
                            else
                            {
                                leftRotate(parent);
                                swapColors(x, grandparent);
                            }
                            // Per il left-left e il left-right
                            rightRotate(grandparent);
                        }
                        else
                        {
                            if (x->isOnLeft())
                            {
                                // for right left
                                // per il right-left
                                rightRotate(parent);
                                swapColors(x, grandparent);
                            }
                            else
                                swapColors(parent, grandparent);
                            // per il right-right e right-left
                            leftRotate(grandparent);
                        }
                    }
                }
            }
            
            // find node that do not have a left child
            // in the subtree of the given node
            Node<value_type> *successor(Node<value_type> *x)
            {
                Node<value_type> *temp = x;
            
                while (temp->left != NULL)
                    temp = temp->left;
            
                return temp;
            }
            

            Node<value_type> *BSTreplace(Node<value_type> *x)
            {
                if (x->left != NULL and x->right != NULL)
                    return successor(x->right);
            

                if (x->left == NULL and x->right == NULL)
                    return NULL;
                if (x->left != NULL)
                    return x->left;
                else
                    return x->right;
            }
    
            // deletes the given node
            void deleteNode(Node<value_type> *v)
            {
                Node<value_type> *u = BSTreplace(v);
            
                // Truequando v e u sono entrambi BLACK
                bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
                Node<value_type> *parent = v->parent;
            
                if (u == NULL)
                {
                    // se u è NULL v è leaf
                    if (v == root)
                        root = NULL; //root è null e v diventa la root
                    else
                    {
                        if (uvBlack)
                            fixDoubleBlack(v); // u e v sono entrambi neri
                                            // v è leaf, aggiusta il doubleBlack
                        else
                        {
                            // u or v is red
                            if (v->sibling() != NULL)
                                v->sibling()->color = RED;
                        }
                        if (v->isOnLeft()) // delete v from the tree cancella v dall' albero
                            parent->left = NULL;
                        else  
                            parent->right = NULL;
                    }
                    delete v;
                    return;
                }
            
                if (v->left == NULL or v->right == NULL)
                {
                    // v ha un figlio
                    if (v == root)
                    {
                        // v è la root, assegna il valore di u a v, e cancella u
                        v->data = u->data;
                        v->left = v->right = NULL;
                        delete u;
                    }
                    else
                    {
                        // stacca v dall'albero e muovi u sopra
                        if (v->isOnLeft())
                            parent->left = u;
                        else 
                            parent->right = u;
                        delete v;
                        u->parent = parent;
                        if (uvBlack) 
                            fixDoubleBlack(u); //u e v sono neri, aggiusta il double black a u
                        else 
                            u->color = BLACK; // u o v rossi, colora u di nero
                    }
                    return;
                }
                // v ha 2 figli, scambia i valori con il successivo e fai la ricorsione
                swapValues(u, v);
                deleteNode(u);
            }
            
            void fixDoubleBlack(Node<value_type> *x)
            {
                if (x == root)
                    return; //x ha raggiunto la root

                Node<value_type> *sibling = x->sibling(), *parent = x->parent;
                if (sibling == NULL)
                    fixDoubleBlack(parent);//Senza sorelle il double black viene spinto
                else
                {
                    if (sibling->color == RED)
                    {
                        // Sibling red
                        parent->color = RED;
                        sibling->color = BLACK;
                        if (sibling->isOnLeft())
                            rightRotate(parent); 
                        else
                            leftRotate(parent);
                        fixDoubleBlack(x);
                    }
                    else
                    {
                        // sorella nera
                        if (sibling->hasRedChild())
                        {
                            //almeno un figlio rosso
                            if (sibling->left != NULL and sibling->left->color == RED)
                            {
                                if (sibling->isOnLeft())
                                {
                                    //left-left
                                    sibling->left->color = sibling->color;
                                    sibling->color = parent->color;
                                    rightRotate(parent);
                                }
                                else
                                {
                                    // right left
                                    sibling->left->color = parent->color;
                                    rightRotate(sibling);
                                    leftRotate(parent);
                                }
                        }
                        else
                        {
                            if (sibling->isOnLeft())
                            {
                                // left right
                                sibling->right->color = parent->color;
                                leftRotate(sibling);
                                rightRotate(parent);
                            }
                            else
                            {
                                // right right
                                sibling->right->color = sibling->color;
                                sibling->color = parent->color;
                                leftRotate(parent);
                            }
                        }
                            parent->color = BLACK;
                        }
                        else
                        {
                            // 2 figli neri
                            sibling->color = RED;
                            if (parent->color == BLACK)
                                fixDoubleBlack(parent);
                            else
                                parent->color = BLACK;
                        }
                    }
                }
            }
            
            // prints level order for given node
            void levelOrder(Node<value_type> *x) {
                if (x == NULL)
                // return if node is null
                return;
            
                // queue for level order
                std::queue<Node<value_type> *> q;
                Node<value_type> *curr;
            
                // push x
                q.push(x);
            
                while (!q.empty()) {
                // while q is not empty
                // dequeue
                curr = q.front();
                q.pop();
            
                // print node value
                std::cout << curr->data.first << " ";
            
                // push children to queue
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
                }
            }
            
            // prints inorder recursively
            void inorder(Node<value_type> *x) {
                if (x == NULL)
                return;
                inorder(x->left);
                std::cout << "first " << x->data.first << " second " << x->data.second << std::endl;
                inorder(x->right);
            }
            
            
            
            
            // searches for given value
            // if found returns the node (used for delete)
            // else returns the last node while traversing (used in insert)
            Node<value_type>* search(const key_type &key)
            {
                Node<value_type>* temp = root;
                while (temp != NULL) {
                if (key < temp->data.first) {
                    if (temp->left == NULL)
                    break;
                    else
                    temp = temp->left;
                } else if (key == temp->data.first) {
                    break;
                } else {
                    if (temp->right == NULL)
                    break;
                    else
                    temp = temp->right;
                }
                }
            
                return temp;
            }
            
            Node<value_type>*   create_node(const value_type &pair_val)
            {
                Node<value_type> * new_node = _allocation.allocate(1);
                _allocation.construct(new_node, pair_val);
                return (new_node);
            }
            
            // inserts the given value to tree
            void insert(const value_type &pair_val)
            {
                pt = create_node(pair_val);
                if (root == NULL)
                {
                    pt->color = BLACK; //se la root è null semplicemente
                    root = pt;          // aggiungi il nuovo nodo come root
                }
                else
                {
                    //cerca il valore pair_val se è gia presente ritorna
                    Node<value_type> *temp = search(pair_val.first);
                    if (temp->data == pair_val) 
                        return;
                //se il valore non è presente, search ritorna il posto
                // in cui deve essere inserito
                pt->parent = temp;
            
                if (pair_val < temp->data)
                    temp->left = pt;
                else
                    temp->right = pt;
            
                // fix red red voilaton if exists
                fixRedRed(pt);
                }
            }
            
            // utility function that deletes the node with given value
            void deleteByVal(const key_type &val)
            {
                //il tree è vuoto
                if (root == NULL)
                    return;
            
                Node<value_type> *v = search(val), *u;
            
                if (v->data.first != val)
                    return;
                deleteNode(v);
                 _size--;
            }
           
            // prints inorder of the tree
            void printInOrder() {
                std::cout << "Inorder: " << std::endl;
                if (root == NULL)
                std::cout << "Tree is empty" <<std::endl;
                else
                inorder(root);
                std::cout << std::endl;
            }
            
            // prints level order of the tree
            void printLevelOrder() {
                std::cout << "Level order: " << std::endl;
                if (root == NULL)
                std::cout << "Tree is empty" << std::endl;
                else
                levelOrder(root);
                std::cout << std::endl;
            }

            pointer     get_root() {return (this->root);};
            size_type   size(){return (this->_size);};

    };
}
#endif