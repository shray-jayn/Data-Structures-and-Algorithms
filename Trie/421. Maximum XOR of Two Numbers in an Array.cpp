#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1); // checks if ith bit is set or not

            if (!node->containsKey(bit))
            {
                node->put(bit, node);
            }

            node = node->get(bit);
        }
    }

public:
    int getMax(int num)
    {
        Node *node = root;

        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1); // checks if ith bit is set or not

            if (node->containsKey(1 - bit)) // if it contains opp. bit
            {
                maxNum = maxNum | (1 << i); // get the max

                node = node->get(1 - bit);
            }

            else
            {
                node = node->get(bit); // just go to next node
            }
        }

        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;

    for (auto &it : arr1)
    {
        trie.insert(it);
    }

    int maxi = 0;

    for (auto &it : arr2)
    {
        maxi = max(maxi, trie.getMax(it));
    }

    return maxi;
}

int findMaximumXOR(vector<int> &nums)
{
    // 1. Insert all the array elements in trie in the form of binary bits
    Trie trie;

    for (int i = 0; i < nums.size(); i++)
    {
        trie.insert(nums[i]);
    }

    int maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, trie.getMax(nums[i]));
    }
    
    return maxi;
}
