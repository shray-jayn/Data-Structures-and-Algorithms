#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using Trie

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch = 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
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
    void insert(string &word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

public:
    vector<string> searchWord(string &prefix)
    {
        int n = prefix.size();

        Node *node = root;

        vector<string> result;

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return {}; // empty vector
            }

            node = node->get(prefix[i]);
        }

        dfs(node, prefix, result);

        return result;
    }

public:
    void dfs(Node *node, string prefix, vector<string> &res)
    {
        if (res.size() == 3)
        {
            return;
        }

        if (node->isEnd() == true)
        {
            res.push_back(prefix);
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->links[i] != NULL)
            {
                dfs(node->links[i], prefix + char(i + 'a'), res);
            }
        }
    }
};

vector<vector<string>> suggestedProducts(vector<string> &products, string Word)
{
    Trie trie;

    int n = Word.size();

    for (int i = 0; i < products.size(); i++)
    {
        trie.insert(products[i]);
    }

    vector<vector<string>> result;
    string prefix = "";

    for (int i = 0; i < n; i++)
    {
        char ch = Word[i];
        prefix += ch;

        result.push_back(trie.searchWord(prefix));
    }
    
    return result;
}

// Using Binary Search

// T.C. O(N * N * logM), M is the size of product array and N is the size of string

// S.C.  O(N * N)

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    int n = searchWord.size();

    // Sort the products

    sort(products.begin(), products.end());

    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
        // Find prefix till ith char ;

        string prefix = searchWord.substr(0, i + 1);

        vector<string> temp;

        // apply lower bound get the index of starting point, where it is matching

        int idx = lower_bound(products.begin(), products.end(), prefix) - products.begin();

        // we can take at most k suggestions

        int k = 3;

        int j = idx;

        while (j < products.size() and k > 0)
        {
            // find the prefix of curr product

            string str = products[j].substr(0, i + 1);

            // if str is not matching with prefix then simply break

            if (str != prefix)
            {
                break;
            }

            // push the curr product into temp array

            temp.push_back(products[j]);

            j++;
            k--;
        }
        // push the temp into res

        result.push_back(temp);
    }
    return result;
}

int main()
{

    return 0;
}
