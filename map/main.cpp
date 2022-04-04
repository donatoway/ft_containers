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
template <class value/*, class alloc = std::allocator<Node<value> *> */>
class RBTree
{
    public:
    typedef value                                value_type;
//    typedef alloc                                allocator_type;
//    typedef typename allocator_type::pointer     pointer;
 //   typedef typename allocator_type::size_type   size_type;

private:
 //   pointer                                 root;
    Node<value_type>                        *root;
 //   allocator_type                      _allocation;
 //   size_type                            _size;
   // allocator_type allocation;
public:
    // Constructor
    RBTree(){root =NULL;};
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
   void insert(const value_type &pair_val)
   {
       //Node<value_type> *pt = new Node<value_type>(pair_val);
        
        Node <value_type> *pt =    new Node<value_type>(pair_val);

        root = RBinsert(root, pt);
    //std::cout << root->right->data.first;
        
   }

   void print()
   {
       
   }

};
 

// Driver Code
int main()
{
    std::pair<int, std::string>     pair_val;
    pair_val = std::make_pair(10, "ciao");

    std::pair<int, std::string>     pair_val2;
    pair_val2 = std::make_pair(20, "dino");

     std::pair<int, std::string>     pair_val3;
    pair_val3 = std::make_pair(30, "dino");

    std::pair<int, std::string>     pair_val4;
    pair_val4 = std::make_pair(40, "dino");

    RBTree<std::pair<int, std::string> > tree;
 
    tree.insert(pair_val);
    tree.insert(pair_val2);
    tree.insert(pair_val3);
    tree.insert(pair_val4);
   /* tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
 */


 //   tree.insert(pair_val);
 //   tree.insert(pair_val2);

 //   cout << "Inorder Traversal of Created Tree\n";
  //  tree.inorder();
 
  //  cout << "\n\nLevel Order Traversal of Created Tree\n";
   // tree.levelOrder();
 
    return 0;
}