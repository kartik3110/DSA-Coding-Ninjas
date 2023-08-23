#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Binary_tree
{
public: // we made it public taki hamien getter aur setter functions na bnane padhe
    T data;
    Binary_tree<T> *left;
    Binary_tree<T> *right;
    Binary_tree(T data)
    {
        this->data = data;
        left = NULL; // garbage set krna is not right,its better if you set it to NULL
        right = NULL;
    }
    ~Binary_tree()
    {                 // if it is single node then on calling left delete NULL will be called and phir delete NULL ignore ho jata hai kuch ni krta delete NULL
        delete left;  // sbse pehle root ka(provided u have written delete root)phir left Node ka destructor call hoga aur phir uske left ka same hi right ke lie hoga aur poora tree will be deleted
        delete right; // lekin deletion destructor poora jab call ho jata uske baad deletion hoti hai
    }
};
// #include "Binary_tree.h" //nai kia because .cpp mein file mein ye file include krne se phle Binary_tree.h ko include kr lia humne
class BST
{
    // Define the data members
    Binary_tree<int> *root;

    // private functions
    Binary_tree<int> *find_minimum(Binary_tree<int> *root)
    {
        if (root->left != NULL)
            return find_minimum(root->left);
        return root;
    }

    Binary_tree<int> *delete_helper(int data, Binary_tree<int> *rootNode)
    {

        if (rootNode == NULL)
        {
            return rootNode;
        }
        if (data > rootNode->data)
        {
            rootNode->right = delete_helper(data, rootNode->right);
        }
        else if (data < rootNode->data)
        {
            rootNode->left = delete_helper(data, rootNode->left);
        }
        else
        {
            if (rootNode->left == NULL && rootNode->right == NULL) // leaf node
            {
                delete rootNode;
                return NULL;
            }
            else if (rootNode->left == NULL || rootNode->right == NULL) // node with 1 child
            {
                if (rootNode->left == NULL)
                {
                    // delete rootNode;// delete rootNode call krne se wo apne neeche poore ke poore tree ko delete kr degi aur uske baad rootNode->right return krne ka toh waise hi sense nai bnta
                    // return rootNode->right;
                    Binary_tree<int> *temp = rootNode->right;
                    rootNode->right = NULL;
                    delete rootNode;
                    return temp;
                }
                if (rootNode->right == NULL)
                {
                    Binary_tree<int> *temp = rootNode->left;
                    rootNode->left = NULL;
                    delete rootNode;
                    return temp;
                }
            }
            // jahan upar se kuch connection krna hai wahan rootNode ko return kr dia nai toh agar wahan pr hi connection ho skta h curreny rootNode ke sath toh wahin pr hi kr dia
            else // two children
            {
                Binary_tree<int> *min_node = find_minimum(rootNode->right);
                //  cout<<min_node->data;
                rootNode->data = min_node->data;
                // cout<<rootNode->data;
                // cout<<rootNode->left->data;
                rootNode->right = delete_helper(min_node->data, rootNode->right); // rootNode->right nai kr rakha tha maine ye mistake tha
                // return rootNode;
                // 2 children wala case left se min nikalke bhi kr skte
            }
        }
    }
    Binary_tree<int> *insert_helper(int data, Binary_tree<int> *rootNode)
    {
        if (rootNode == NULL)
        {
            Binary_tree<int> *node = new Binary_tree<int>(data);
            rootNode = node;
            return rootNode;
        }
        else if (data > rootNode->data)
        {
            Binary_tree<int> *node = insert_helper(data, rootNode->right);
            rootNode->right = node;
        }
        else
        {
            Binary_tree<int> *node = insert_helper(data, rootNode->left);
            rootNode->left = node;
        }
        return rootNode;
    }
    bool getData_helper(int data, Binary_tree<int> *root)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;
        else if (data < root->data)
        {
            return getData_helper(data, root->left);
        }
        else
        {
            return getData_helper(data, root->right);
        }
    }
    void print_helper(Binary_tree<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print_helper(root->left);
        print_helper(root->right);
    }

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
        root = delete_helper(data, root);
    }

    void print()
    {
        // Implement the print() function
        print_helper(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
        root = insert_helper(data, root);
    }

    bool search(int data)
    {
        // Implement the search() function
        return getData_helper(data, root);
    }
};
int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.print();
    cout << endl;
    b.remove(10);
    b.print();
}