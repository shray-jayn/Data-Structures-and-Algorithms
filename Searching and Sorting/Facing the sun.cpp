#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countBuildings(int arr[], int n)
{
    // code here
    int cnt = 0;
    int tre = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > tre)
        {
            cnt++;
            tre = arr[i];
        }
    }
    return cnt;
}
int main()
{

    return 0;
}