#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int getSize(unordered_map<string, unordered_set<string>> &tree, string &manager, unordered_map<string, int> &result)
{

    if (tree.find(manager) == tree.end())
    {
        result[manager] = 0;
        return 1;
    }

    int sz = 0;

    for (string emp : tree[manager])
    {
        int childSize = getSize(tree, emp, result);
        sz += childSize;
    }

    result[manager] = sz;

    return sz + 1;
}

void findCount(unordered_map<string, string> &mp)
{
    unordered_map<string, unordered_set<string>> tree;

    string ceo = "";

    for (auto it : mp)
    {
        string manager = it.first;
        string emp = it.second;

        if (manager == emp)
        {
            ceo = manager;
        }
        else
        {
            if (tree.find(manager) != tree.end())
            {
                unordered_set<string> employees = tree[manager];
                employees.insert(emp);
            }
            else
            {
                unordered_set<string> employees;
                employees.insert(emp);
                tree[manager] = employees;
            }
        }
    }

    unordered_map<string, int> result;

    int siZe = getSize(tree, ceo, result);




}

int main()
{

    return 0;
}