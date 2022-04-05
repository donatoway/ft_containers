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
 
 template <class value_type>
struct Node
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
template <class value_type>
class RBTree
{
private:
    Node<value_type> *root;
protected:
    void rotateLeft(Node<value_type> *&, Node<value_type> *&);
    void rotateRight(Node<value_type> *&, Node<value_type> *&);
    void fixViolation(Node<value_type> *&, Node<value_type> *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const value_type &n);
    void inorder();
    void levelOrder();
};
 
// A recursive function to do inorder traversal
template <class value_type>
void inorderHelper(Node<value_type> *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->data.first << "  ";
    inorderHelper(root->right);
}
 
/* A utility function to insert
    a new node with given key

   in BST */
template <class value_type>
Node<value_type>* BSTInsert(Node<value_type>* root, Node<value_type> *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
 
    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}
 
// Utility function to do level order traversal
template <class value_type>
void levelOrderHelper(Node<value_type> *root)
{
    if (root == NULL)
        return;
 
    std::queue< Node<value_type> *> q;
    q.push(root);
 
    while (!q.empty())
    {
         Node<value_type> *temp = q.front();
        cout << temp->data.first << "  ";
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
 
 template <class value_type>
void RBTree<value_type>::rotateLeft(Node<value_type> *&root, Node<value_type> *&pt)
{
     Node<value_type> *pt_right = pt->right;
 
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
  template <class value_type>
void RBTree<value_type>::rotateRight(Node<value_type> *&root, Node<value_type> *&pt)
{
     Node<value_type> *pt_left = pt->left;
 
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
 template <class value_type>
void RBTree<value_type>::fixViolation(Node<value_type> *&root, Node<value_type> *&pt)
{
    Node<value_type> *parent_pt = NULL;
    Node<value_type> *grand_parent_pt = NULL;
 
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
 
             Node<value_type> *uncle_pt = grand_parent_pt->right;
 
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
            Node<value_type> *uncle_pt = grand_parent_pt->left;
 
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
 template <class value_type>
void RBTree<value_type>::insert(const value_type &data)
{
    Node<value_type> *pt = new Node<value_type>(data);
 
    // Do a normal BST insert
    root = BSTInsert(root, pt);
    // fix Red Black Tree violations
    fixViolation(root, pt);
}
 
// Function to do inorder and level order traversals
 template <class value_type>
void RBTree<value_type>::inorder()     {  inorderHelper(root);}
 template <class value_type>
void RBTree<value_type>::levelOrder()  {  levelOrderHelper(root); }
 
// Driver Code
int main()
{
   std::pair<int, std::string>     pair_val;
    pair_val = std::make_pair(10, "ciao");


    RBTree<std::pair<int, std::string> > tree;
 
    tree.insert(pair_val);
  
 
  /* cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();
 
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
*/
    return 0;
}