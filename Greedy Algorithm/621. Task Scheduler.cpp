#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int leastInterval(vector<char> &tasks, int n)
{
    int m = tasks.size();

    unordered_map<char, int> mp;

    for (int i = 0; i < m; i++)
    {
        mp[tasks[i]]++;
    }

    priority_queue<int> pq;

    for (auto it : mp)
    {
        pq.push(it.second);
    }

    int result = 0;

    while (!pq.empty())
    {
        int time = 0;
        vector<int> temp;

        for (int i = 0; i < n + 1; i++)
        {
            if (!pq.empty())
            {
                int curr = pq.top();
                temp.push_back(curr - 1);
                pq.pop();
                time++;
            }
        }

        for (auto it : temp)
        {
            if (it != 0)
            {
                pq.push(it);
            }
        }

        if (pq.empty() == true)
        {
            result += time;
        }
        else
        {
            result += n + 1;
        }
    }
    return result;
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl;

    return 0;
}