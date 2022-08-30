#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maximumSwap(int num)
{
    string n = to_string(num);

    // Keep in a map the last accurance of each digit:
    unordered_map<int, int> last;

    for (int i = 0; i < n.size(); i++)
        last[n[i] - '0'] = i;

    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 9; j > n[i] - '0'; j--)
        {

            // If there's a larger digit later - swap:
            if (last[j] > i)
            {
                swap(n[last[j]], n[i]);
                return stoi(n);
            }
        }
    }
    
    return stoi(n);
}

int main()
{

    return 0;
}