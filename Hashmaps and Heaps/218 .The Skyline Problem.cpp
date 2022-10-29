#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> ans;

    vector<pair<int, int>> List;

    for (int i = 0; i < buildings.size(); i++)
    {
        int sp = buildings[i][0];
        int ep = buildings[i][1];
        int ht = buildings[i][2];

        List.push_back({sp, -ht});
        List.push_back({ep, ht});
    }

    sort(List.begin(), List.end());

    priority_queue<int> pq; // Max Heap

    int currentHeight = 0;
    pq.push(0);

    for (int i = 0; i < List.size(); i++)
    {
        int x = List[i].first;
        int ht = List[i].second;

        if (ht < 0) // starting point
        {
            ht = -ht;
            pq.push(ht);
        }
        else // ending point
        {
            pq.pop();
        }

        if (currentHeight != pq.top())
        {
            vector<int> temp;
            temp.push_back(x);
            temp.push_back(pq.top());

            ans.push_back(temp);
            currentHeight = pq.top();
        }
    }

    return ans;
}

static bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}


vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> list;
    vector<vector<int>> ans;

    for (auto x : buildings)
    {

        list.push_back({x[0], -x[2]});
        list.push_back({x[1], x[2]});
    }

    sort(list.begin(), list.end(), comp);
    // for(auto x : list) {
    //     cout<<" [" << x.first << ", " << x.second << "] ";
    // }

    multiset<int> pq;
    pq.insert(0);
    int current_height = 0;
    for (auto x : list)
    {

        if (x.second < 0)
        {
            // starting point
            pq.insert(-x.second);
            if (*pq.rbegin() > current_height)
            {
                ans.push_back({x.first, -x.second});
                current_height = -x.second;
            }
        }
        else
        {
            pq.erase(pq.find(x.second));
            if (*pq.rbegin() < current_height)
            {
                ans.push_back({x.first, *pq.rbegin()});
                current_height = *pq.rbegin();
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}