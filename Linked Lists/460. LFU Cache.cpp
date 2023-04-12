#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int key;
    int value;
    int cnt;
    Node *prev;
    Node *next;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List // Class for Doubly linked list LRU Cache
{
    int size;
    Node *head;
    Node *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node *newNode) // add a new node next to head node and increase size of list
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
        size++;
    }

    void removeNode(Node *delNode) // delete node with given address and reduce size
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache
{

    map<int, Node *> keyNode;
    map<int, List *> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key); // remove node from both the maps
        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq and freqListMap[node->cnt]->size == 0) // check if node's freq was minFreq and there is no other element with minfrequency
        {
            minFreq++; // update the min frequency
        }

        List *nextHigherFreqList = new List(); // create a new list

        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) // check if list at new freq exists
        {
            nextHigherFreqList = freqListMap[node->cnt + 1]; // add all the elements of that list in new list
        }

        node->cnt += 1; // increase freq of node

        nextHigherFreqList->addNode(node); // add node to newList

        freqListMap[node->cnt] = nextHigherFreqList; // update both the maps by adding list and node
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end()) // get that node then update the freqListMap and return value of node
        {
            Node *node = keyNode[key];
            int val = node->value;

            updateFreqListMap(node);

            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }

        if (keyNode.find(key) != keyNode.end()) // if key is already present
        {
            Node *node = keyNode[key]; // get the node and update the value
            node->value = value;

            updateFreqListMap(node); // update the freq list
        }

        else
        {
            if (curSize == maxSizeCache) // if Cache is full
            {
                List *list = freqListMap[minFreq]; // get the list woth minimum frequency

                // remove the LRU node of the list (which is the last node i.e. node before tail)

                keyNode.erase(list->tail->prev->key);               // removes node from the map
                freqListMap[minFreq]->removeNode(list->tail->prev); // remove last node from list

                curSize--;
            }

            curSize++; // increase size of cache

            minFreq = 1; // new element would be that who was not present previoulsy so it's freq =1 ;

            List *listFreq = new List(); // create a new list

            if (freqListMap.find(minFreq) != freqListMap.end()) // check if list at new freq exists
            {
                listFreq = freqListMap[minFreq]; // add all the elements of that list in new list
            }

            Node *node = new Node(key, value); // create new node

            listFreq->addNode(node); // add node to list

            keyNode[key] = node; // update both the maps by adding list and node
            freqListMap[minFreq] = listFreq;
        }
    }
};

int main()
{

    return 0;
}