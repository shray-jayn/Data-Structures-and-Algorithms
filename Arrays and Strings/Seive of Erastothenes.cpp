#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countPrimes(int n)
{
    // Handing the case of n=0

    if (n == 0)
    {
        return 0;
    }

    // A vector that first marks all the number between 0 and n as prime

    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;

    // counter to count the number of prime

    int count = 0;

    // Now, running a loop from 2 to n (marked 0 and 1 as not-prime already)

    for (int i = 2; i < n; i++)
    {
        // Check if v[i] is prime

        if (v[i])
        {
            count++;

            int k = 2;

            // if v[i] is prime then all its multiple that are less then n are
            // non-prime
            
            for (int j = i * 2; j < n; j = i * k)
            {
                v[j] = false;
                k++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}