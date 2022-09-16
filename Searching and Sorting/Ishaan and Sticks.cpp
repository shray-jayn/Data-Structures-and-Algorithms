#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> square(int arr[], int n)
{
    // Complete the function
    map<int, int> mp;
    int fre = 0;
    int ele = 0;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second >= 4)
        {
            fre = it.second / 4;
            ele = it.first;
        }
    }
    vector<int> answer;
    if (fre == 0 && ele == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        answer.push_back((ele * ele));
        answer.push_back((fre));
    }
    return answer;
}
