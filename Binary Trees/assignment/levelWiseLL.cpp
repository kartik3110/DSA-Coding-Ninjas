#include <iostream>
#include <queue>
using namespace std;

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

template <typename T>
class LLnode
{
public:
    T data;
    LLnode<T> *next;
    LLnode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

vector<LLnode<int> *> constructLinkedListForEachLevel(node<int> *root)
{
    // return an array of Linked lists' heads
    vector<LLnode<int> *> ans;
    if (!root)
    {
        return ans;
    }
    queue<node<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    LLnode<int> *dummyNode = new LLnode<int>(0);
    LLnode<int> *head = dummyNode;
    while (!pendingNodes.empty())
    {
        node<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        if (frontNode)
        {
            head->next = new LLnode<int>(frontNode->data);
            head = head->next;
            if (frontNode->left)
                pendingNodes.push(frontNode->left);
            if (frontNode->right)
                pendingNodes.push(frontNode->right);
        }
        else if (frontNode == NULL)
        {
            ans.push_back(dummyNode->next);
            head = dummyNode;
            if (pendingNodes.empty())
            {
                return ans;
            }
            pendingNodes.push(NULL);
        }
    }
    return ans;
}
// other approach
//  vector<Node<int> *> v = {NULL};
//   if (root == NULL)
//     return v;
//   else
//     v.clear();
//   queue<BinaryTreeNode<int> *> pendingNodes;
//   pendingNodes.push(root);
//   while (pendingNodes.size() != 0) {
//     int n = pendingNodes.size();
//     Node<int> *head = NULL;
//     Node<int> *tail = NULL;
//     while (n != 0) {
//       BinaryTreeNode<int> *front = pendingNodes.front();
//       pendingNodes.pop();
//       Node<int> *newNode = new Node<int>(front->data);
//       if (head == NULL) {
//         head = newNode;
//         tail = newNode;
//       } else {
//         tail->next = newNode;
//         tail = newNode;
//       }
//       if (front->left != NULL)
//         pendingNodes.push(front->left);
//       if (front->right != NULL)
//         pendingNodes.push(front->right);
//       n--;
//     }
//     v.push_back(head);
//   }
//   return v;