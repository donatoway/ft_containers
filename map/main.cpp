/*#include <iostream>
#include <map>


using namespace std;

int main()
{
    map<string, string> uomo;
   

    uomo.insert(pair<string, string>("angelo", "cuoco"));
    uomo.insert(pair<string, string>("angeloo", "fabbro"));
    uomo.insert(pair<string, string>("bino", "meccanico"));

    map<string, string>::iterator itr;

    for (itr = uomo.begin() ;itr != uomo.end();itr++)
    {
       cout << itr->first << "-" << itr->second <<  endl;
    }
    //continuare a vedere tree (gli alberi lezioni su youtube), documentazione ecc...
    
}

*/


/** C++ implementation for
   Red-Black Tree Insertion
   This code is adopted from
   the code provided by
   Dinesh Khandelwal in comments **/
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
 
enum Color {RED, BLACK};
 
template < class value>
struct Node
{
    value data;
    bool color;
    Node *left, *right, *parent;
 
    // Constructor
    Node(value data)
    {
       this->data = data;
       left = right = parent = NULL;
       this->color = RED;
    }
};
 
// Class to represent Red-Black Tree
template <class value>
class RBTree
{
private:
    Node<value> *root;
protected:
    void rotateLeft(Node<value> *&, Node<value> *&);
    void rotateRight(Node<value> *&, Node<value> *&);
    void fixViolation(Node<value> *&, Node<value> *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const value &n);
    void inorder();
    void levelOrder();
};
 
// A recursive function to do inorder traversal

template <class value>
void inorderHelper(Node<value> *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}
 
/* A utility function to insert
    a new node with given key
   in BST */

template <class value>
Node<value>* BSTInsert(Node<value>* root, Node<value> *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
 
    /* Otherwise, recur down the tree */
   // std::cout << pt->data.second;
   // std::cout << root->data.second;
    if (pt->data < root->data)
    {
        std::cout << "ciao";
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        std::cout << "dino";
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}
 
// Utility function to do level order traversal

template <class value>
void levelOrderHelper(Node<value> *root)
{
    if (root == NULL)
        return;
 
    std::queue<Node<value> *> q;
    q.push(root);
 
    while (!q.empty())
    {
        Node<value> *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
 


template <class value>
void RBTree<value>::rotateLeft(Node<value> *&root, Node<value> *&pt)
{
    Node<value> *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}
 
template <class value>
void RBTree<value>::rotateRight(Node<value> *&root, Node<value> *&pt)
{
    Node<value> *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}
 
// This function fixes violations
// caused by BST insertion
template <class value>
void RBTree<value>::fixViolation(Node<value> *&root, Node<value> *&pt)
{
    Node<value> *parent_pt = NULL;
    Node<value> *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        /*  Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
 
            Node<value> *uncle_pt = grand_parent_pt->right;
 
            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color ==
                                                   RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
 
            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                           grand_parent_pt->color);
                pt = parent_pt;
            }
        }
 
        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else
        {
            Node<value> *uncle_pt = grand_parent_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                                                    RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                         grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
 
    root->color = BLACK;
}
 
// Function to insert a new node with given data
template <class value>
void RBTree<value>::insert(const value &data)
{
    Node<value> *pt = new Node<value>(data);
 
    // Do a normal BST insert
    root = BSTInsert(root, pt);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}
 
// Function to do inorder and level order traversals
template <class value>
void RBTree<value>::inorder()     {  inorderHelper(root);}
template <class value>
void RBTree<value>::levelOrder()  {  levelOrderHelper(root); }
 
// Driver Code
int main()
{
    std::pair<int, std::string>     pair_val;
    pair_val = std::make_pair(10, "ciao");

    std::pair<int, std::string>     pair_val2;
    pair_val2 = std::make_pair(10, "dino");

    RBTree<std::pair<int, std::string> > tree;
 
   /* tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
 */


    tree.insert(pair_val);
    tree.insert(pair_val2);

    cout << "Inorder Traversal of Created Tree\n";
  //  tree.inorder();
 
    cout << "\n\nLevel Order Traversal of Created Tree\n";
   // tree.levelOrder();
 
    return 0;
}