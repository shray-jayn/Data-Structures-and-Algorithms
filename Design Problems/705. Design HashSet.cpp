#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class MyHashSet
{
private:
    std::vector<bool> mp;

public:
    MyHashSet()
    {
        mp.resize(1000001, false);
    }

    void add(int key)
    {
        mp[key] = true;
    }

    void remove(int key)
    {
        mp[key] = false;
    }

    bool contains(int key)
    {
        return mp[key];
    }
};

int main()
{

    return 0;
}