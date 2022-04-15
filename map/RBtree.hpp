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
                Node<value_type> temp;
                temp = u->val;
                u->val = v->val;
                v->val = temp;
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
            /*
            // find node that do not have a left child
            // in the subtree of the given node
            Node *successor(Node *x) {
                Node *temp = x;
            
                while (temp->left != NULL)
                temp = temp->left;
            
                return temp;
            }
            
            // find node that replaces a deleted node in BST
            Node *BSTreplace(Node *x) {
                // when node have 2 children
                if (x->left != NULL and x->right != NULL)
                return successor(x->right);
            
                // when leaf
                if (x->left == NULL and x->right == NULL)
                return NULL;
            
                // when single child
                if (x->left != NULL)
                return x->left;
                else
                return x->right;
            }
            
            // deletes the given node
            void deleteNode(Node *v) {
                Node *u = BSTreplace(v);
            
                // True when u and v are both black
                bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
                Node *parent = v->parent;
            
                if (u == NULL) {
                // u is NULL therefore v is leaf
                if (v == root) {
                    // v is root, making root null
                    root = NULL;
                } else {
                    if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    fixDoubleBlack(v);
                    } else {
                    // u or v is red
                    if (v->sibling() != NULL)
                        // sibling is not null, make it red"
                        v->sibling()->color = RED;
                    }
            
                    // delete v from the tree
                    if (v->isOnLeft()) {
                    parent->left = NULL;
                    } else {
                    parent->right = NULL;
                    }
                }
                delete v;
                return;
                }
            
                if (v->left == NULL or v->right == NULL) {
                // v has 1 child
                if (v == root) {
                    // v is root, assign the value of u to v, and delete u
                    v->val = u->val;
                    v->left = v->right = NULL;
                    delete u;
                } else {
                    // Detach v from tree and move u up
                    if (v->isOnLeft()) {
                    parent->left = u;
                    } else {
                    parent->right = u;
                    }
                    delete v;
                    u->parent = parent;
                    if (uvBlack) {
                    // u and v both black, fix double black at u
                    fixDoubleBlack(u);
                    } else {
                    // u or v red, color u black
                    u->color = BLACK;
                    }
                }
                return;
                }
            
                // v has 2 children, swap values with successor and recurse
                swapValues(u, v);
                deleteNode(u);
            }
            
            void fixDoubleBlack(Node *x) {
                if (x == root)
                // Reached root
                return;
            
                Node *sibling = x->sibling(), *parent = x->parent;
                if (sibling == NULL) {
                // No sibiling, double black pushed up
                fixDoubleBlack(parent);
                } else {
                if (sibling->color == RED) {
                    // Sibling red
                    parent->color = RED;
                    sibling->color = BLACK;
                    if (sibling->isOnLeft()) {
                    // left case
                    rightRotate(parent);
                    } else {
                    // right case
                    leftRotate(parent);
                    }
                    fixDoubleBlack(x);
                } else {
                    // Sibling black
                    if (sibling->hasRedChild()) {
                    // at least 1 red children
                    if (sibling->left != NULL and sibling->left->color == RED) {
                        if (sibling->isOnLeft()) {
                        // left left
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rightRotate(parent);
                        } else {
                        // right left
                        sibling->left->color = parent->color;
                        rightRotate(sibling);
                        leftRotate(parent);
                        }
                    } else {
                        if (sibling->isOnLeft()) {
                        // left right
                        sibling->right->color = parent->color;
                        leftRotate(sibling);
                        rightRotate(parent);
                        } else {
                        // right right
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        leftRotate(parent);
                        }
                    }
                    parent->color = BLACK;
                    } else {
                    // 2 black children
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
            void levelOrder(Node *x) {
                if (x == NULL)
                // return if node is null
                return;
            
                // queue for level order
                queue<Node *> q;
                Node *curr;
            
                // push x
                q.push(x);
            
                while (!q.empty()) {
                // while q is not empty
                // dequeue
                curr = q.front();
                q.pop();
            
                // print node value
                cout << curr->val << " ";
            
                // push children to queue
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
                }
            }
            
            // prints inorder recursively
            void inorder(Node *x) {
                if (x == NULL)
                return;
                inorder(x->left);
                cout << x->val << " ";
                inorder(x->right);
            }
            
            public:
            // constructor
            // initialize root
            RBTree() { root = NULL; }
            
            */
            
            // searches for given value
            // if found returns the node (used for delete)
            // else returns the last node while traversing (used in insert)
            Node<value_type>* search(const value_type &pair_val)
            {
                Node<value_type>* temp = root;
                while (temp != NULL) {
                if (pair_val < temp->data) {
                    if (temp->left == NULL)
                    break;
                    else
                    temp = temp->left;
                } else if (pair_val == temp->data) {
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
                    Node<value_type> *temp = search(pair_val);
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
      /*      void deleteByVal(int n) {
                if (root == NULL)
                // Tree is empty
                return;
            
                Node *v = search(n), *u;
            
                if (v->val != n) {
                cout << "No node found to delete with value:" << n << endl;
                return;
                }
            
                deleteNode(v);
            }
            
            // prints inorder of the tree
            void printInOrder() {
                cout << "Inorder: " << endl;
                if (root == NULL)
                cout << "Tree is empty" << endl;
                else
                inorder(root);
                cout << endl;
            }
            
            // prints level order of the tree
            void printLevelOrder() {
                cout << "Level order: " << endl;
                if (root == NULL)
                cout << "Tree is empty" << endl;
                else
                levelOrder(root);
                cout << endl;
            }
*/
             pointer     get_root() {return (this->root);};
                size_type   size(){return (this->_size);};

    };
}
#endif