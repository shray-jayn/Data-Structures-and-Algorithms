#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int sizeLL(Node *head)
{
    Node *curr = head;
    int size = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        size++;
    }

    return size;
}

void addFisrtNode(Node *head, Node *tail, int val)
{
    Node *node = new Node(val);

    if (sizeLL(head) == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void addFisrt(Node *head, Node *tail, int val)
{
     
}

int main()
{

    return 0;
}