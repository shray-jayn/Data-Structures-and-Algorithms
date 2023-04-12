#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *prev;
        node *next;

        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    // Create dummy head and tail pointers

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mp; // <key,address>

    LRUCache(int capacity) // Initial Configuration
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *newNode) // add a new node next to head node
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(node *delNode) // delete node with given address
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_)
    {
        if (mp.find(key_) != mp.end())
        {
            node *resNode = mp[key_];

            int res = resNode->val;

            mp.erase(key_); // erase the key from map and delete from list
            deleteNode(resNode);

            addNode(resNode); // add key before tail in list and update its address in map
            mp[key_] = head->next;

            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (mp.find(key_) != mp.end())
        {
            node *existingNode = mp[key_];

            mp.erase(key_); // delete from map and list
            deleteNode(existingNode);
        }

        if (mp.size() == cap) // if cache is full
        {
            mp.erase(tail->prev->key); // delete the LRU node
            deleteNode(tail->prev);
        }

        addNode(new node(key_, value)); // add the new node to Cache
        mp[key_] = head->next;
    }
};

int main()
{

    return 0;
}
