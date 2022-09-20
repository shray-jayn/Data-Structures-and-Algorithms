#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> sortArrayByParity(vector<int> &A)
{
    for (int i = 0, j = 0; j < A.size(); j++)
    {
        if (A[j] % 2 == 0)
        {
            swap(A[i++], A[j]);
        }
    }
    
    return A;
}

int main()
{

    return 0;
}