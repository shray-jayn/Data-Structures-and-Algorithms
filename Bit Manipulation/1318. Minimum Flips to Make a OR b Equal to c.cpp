#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minFlips(int a, int b, int c)
{
    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        bool ai = false;
        bool bi = false;
        bool ci = false;

        if ((a & (1 << i)) > 0) // a->ith bit is set
        {
            ai = true;
        }
        if ((b & (1 << i)) > 0) // b->ith bit is set
        {
            bi = true;
        }
        if ((c & (1 << i)) > 0) // c->ith bit is set
        {
            ci = true;
        }

        if (ci == true)
        {
            if (bi == false and ai == false)
            {
                ans++;
            }
        }
        else
        {
            if (ai == true and bi == true)
            {
                ans += 2;
            }

            else if (ai == true or bi == true)
            {
                ans++;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}