#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minimumDays(int S, int N, int M)
{  // Total required food to survive
  //  all S days
    int reqfood = M * S;

    // If days are less than 7 and food
    // req per day if more than what
    // is available per day then she
    // cant survive
    if (S < 7 && N < M)
        return -1;

    // if days are more than 7 and
    //   total food req to survive 7 days
    // is more than what we can buy in
    // 6 days , then we cant survive
    if (S >= 7 && 6 * N < 7 * M)
        return -1;

    // simple now
    return reqfood % N == 0 ? reqfood / N : (reqfood / N) + 1;
}

int main()
{

    return 0;
}