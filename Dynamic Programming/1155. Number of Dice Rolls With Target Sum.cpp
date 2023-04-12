#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MOD = 1e9 + 7;

int f(int k, int n, int num, int target, int cur)
{

    // whenever we reach the number of dices allowed and target is not equal to our cur sum we return 0
    if (n == num and target != cur)
        return 0;
    // whenever we reach the number of dices allowed and target is equal to our cur sum we return 1
    if (n == num and target == cur)
        return 1;

    // define a long int total for storing the number of ways
    long long total = 0;

    // iterate for k times, for all the k faces of the dice
    for (int i = 1; i <= k; i++)
    {

        // add all the occuring chances to our total
        total += f(k, n, num + 1, target, cur + i);
    }

    // return the answer by taking it's modulus as specified in the question
    return total % MOD;
}

int numRollsToTarget(int n, int k, int target)
{

    return f(k, n, 0, target, 0);
}

int main()
{

    return 0;
}