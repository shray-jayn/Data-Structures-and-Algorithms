#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    struct TrieNode
    {
        TrieNode *child[26];
        int count;
        bool isEnd;

        TrieNode()
        {
            count = 0;
            isEnd = 0;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    void insert(TrieNode *root, string key)
    {
        TrieNode *curr = root;
        for (int i = 0; i < key.size(); i++)
        {
            int index = key[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr->child[index]->count += 1;
            curr = curr->child[index];
        }
        curr->count += 1;
        curr->isEnd = 1;
    }

    string search(TrieNode *root, string key)
    {
        TrieNode *curr = root;

        string temp = "";

        for (int i = 0; i < key.size(); i++)
        {
            int index = key[i] - 'a';

            if (curr->child[index]->count == 1)
            {
                temp += key[i];
                return temp;
            }

            // curr -> child[i] -> count += 1;

            temp += key[i];
            
            curr = curr->child[index];
        }
        if (curr->isEnd)
            return temp;
    }

public:
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            insert(root, arr[i]);
        }
        vector<string> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = search(root, arr[i]);
        }
        return res;
    }
};

int main()
{

    return 0;
}