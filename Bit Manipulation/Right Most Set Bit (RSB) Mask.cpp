#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    int rmsb = n & (-n);

    cout << rmsb << endl; 
        
    return 0;
}