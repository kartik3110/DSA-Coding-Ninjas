#include <iostream>
#include <cstring>
#include <vector>
#include "treeNode.cpp"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData, n;
    cout << "enter data: " << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    cout << "enter no. of children: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    cout << root->data << ": ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }

    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
int main()
{
    char arr[10] = {'*'};
    cout << arr;

    return 0;
}