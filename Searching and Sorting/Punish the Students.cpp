#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int shouldPunish(int roll[], int marks[], int n, double avg)
{
    int sumMarks = 0;
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        sumMarks += marks[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (roll[j] > roll[j + 1])
            {
                swaps++;
                int temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;
            }
        }
    }
    
    int fakeAvg = (sumMarks - swaps) / n;
    return fakeAvg >= avg ? 1 : 0;
}

int main()
{

    return 0;
}