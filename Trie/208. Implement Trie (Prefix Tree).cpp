#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch = 'a'];
    }

    bool setEnd()
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

    // T.C. Insert => O(length of word);

    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i])) // if it does not contains key
            {
                node->put(word[i], new Node());
            }

            node->get(word[i]); // moves to the reference trie
        }

        node->setEnd();
    }


    // T.C. Search => O(length of word);

    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return (node->isEnd());
    }

    // T.C. startsWith => O(length of word);

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main()
{

    return 0;
}