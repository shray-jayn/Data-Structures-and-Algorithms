#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n, i, j, k, m;

    cin >> n, i, j, k, m;

    int onMask = (1 << i);
    int offMask = ~(1 << j);
    int toggleMask = (1 << k);
    int checkMask = (1 << m);

    cout << (n or onMask) << endl;
    cout << (n and offMask) << endl;
    cout << (n ^ toggleMask) << endl;
    cout << ((n and checkMask) == 0 ? false : true) << endl;
}