#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SnapshotArray
{
public:
    unordered_map<int, int> snapArray;              // it stores <index, val>
    unordered_map<int, unordered_map<int, int>> mp; // it stores <id, map<index,val>>
    int snapId = 0;

    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        snapArray[index] = val;
    }

    int snap()
    {
        mp[snapId] = snapArray;
        return snapId++;
    }

    int get(int index, int snap_id)
    {
        return mp[snap_id][index];
    }
};

int main()
{

    return 0;
}