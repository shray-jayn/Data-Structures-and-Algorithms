#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void completeTask(int n, int m, vector<int> arr)
{
    unordered_set<int> completed;

    for (int i = 0; i < m; i++)
    {
        completed.insert(arr[i]);
    }

    vector<int> one;
    vector<int> two;
    bool flag = true;

    for (int i = 1; i <= n; i++)
    {
        if (completed.find(i) == completed.end())
        {
            if (flag == true)
            {
                one.push_back(i);
            }
            else
            {
                two.push_back(i);
            }
            flag = !flag;
        }
    }

}

int main()
{

    return 0;
}