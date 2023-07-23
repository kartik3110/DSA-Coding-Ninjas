#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isWordPalindrome(string word)
    {
        int i = 0;
        int j = word.size() - 1;
        while (i < j)
        {
            if (word[i] != word[j])
                return false;
        }
        return true;
    }

    bool isPalindromeHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {

            string s = "";
        }
        int index = word[0] - 'a';
        if (!root->children[index])
        {
            return false;
        }
        return isPalindromeHelper(root->children[index], word.substr(1));
    }

    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        // add each word in the trie and then search for opposite of every word
        for (int i = 0; i < words.size(); i++)
        {
            add(words[i]);
        }
        for (int i = 0; i < words.size(); i++)
        {
            reverse(words[i].begin(), words[i].end());
            if (isPalindromeHelper(root, words[i]))
            {
                return true;
            }
        }
        return false;
    }
};