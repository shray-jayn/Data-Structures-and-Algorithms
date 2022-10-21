#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 8, 10, 11, 12, 19};
    int target = 9;

    vector<int>::iterator j;

    j = upper_bound(v.begin(), v.end(), target);
    cout << j - v.begin() << endl;
}