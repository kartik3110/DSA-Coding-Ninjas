template <typename T>
class node
{
public:
    T data;
    node *left;
    node *right;

    node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~node()
    {
        delete left;
        delete right; // now we can call delete root
    }
};
