#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxStep(int arr[], int n)
{
    int maxStep = 0;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
        }
        else
        {
            maxStep = max(maxStep, count);
            count = 0;
        }
    }

    maxStep= max(maxStep,count);

    return maxStep;
}

int main()
{

    return 0;
}