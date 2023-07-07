#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class NumberContainers
{
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> ms;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (mp[index] == 0)
        {
            mp[index] = number;
            ms[number].insert(index);
        }
        else
        {
            ms[mp[index]].erase(index);
            mp[index] = number;
            ms[number].insert(index);
        }
    }

    int find(int number)
    {
        if (ms[number].empty())
        {
            return -1;
        }
        else
        {
            return *ms[number].begin();
        }
    }
};

int main()
{

    return 0;
}