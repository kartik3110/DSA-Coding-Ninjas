#include <iostream>
#include <string>
#include "TrieNode.cpp"
using namespace std;

class Trie
{
    TrieNode *root;

    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            // call recursively on the found node
        }
        else
        {
            child = new TrieNode(word[0]);
        }
        insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if (root->children[index])
        {
            return search(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }

    void remove(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return; // word not found
        }
        TrieNode *child = root->children[index];
        remove(child, word.substr(1));
        if (child->isTerminal == false) // if child node wasnt terminal and had no children, remove it
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            // child did not have any children
            delete child;
            root->children[index] = NULL;
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void remove(string word)
    {
        remove(root, word);
    }
};
