#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxSubstring(string S)
{ // Kadane's Algorithm

    int sum = 0, maximum = -1;

    for (int i = 0; i < S.length(); i++)
    {
        if (sum < 0)
        {            // when ever sum goes negative
            sum = 0; // initilize it again with 0
        }
        if (S.at(i) == '0')
            sum++; // according to question 0 is taken as +1 and
        else
            sum--; //  1 is taken as -1

        maximum = max(sum, maximum); // make comparison and choose the maximum
                                     // doing the comparison at last also eliminate
                                     // any chances of getting all 1's present in array
    }

    return maximum;
}

int main()
{

    return 0;
}