#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

uint32_t reverseBits(uint32_t n)
{
}

int main()
{
    int n;
    cin >> n;

    bool flag = 0;

    int rev = 0;
    int j = 0;

    for (int i = 31; i >= 0; i--)
    {
        int mask = (1 << i);

        if (flag == true)    
        {
            if ((n & mask) != 0) // bit is on
            {
                cout << 1;

                int setMask = (1 << j);       // us bit ko add kar dia reverse me mask ke sath or karke 
                rev = rev or setMask;
            }
            else // bit is off
            {
                cout << 0;
            }

            j++;  // j ko move kara 
        }
        else
        {
            if ((n & mask) != 0) // bit is on
            {
                flag = 1; // humko pehla flag mil chuka hai

                cout << 1;

                int setMask = (1 << j);

                rev = rev or setMask;
                j++;
            }
            else // bit is off
            {
                continue; // as these are initial zeros
            }
        }
    }
    return 0;
}