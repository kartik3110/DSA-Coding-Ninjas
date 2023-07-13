#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next; // points to next node

public:
    node(int data) // constructor
    {
        this->data = data;
        next = NULL;
    }
};