#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef pair<int, pair<int, int>> pr;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    int n = nums.size();

    vector<int> range = {-100000, 100000};

    // make a MIN heap ;

    priority_queue<pr, vector<pr>, greater<pr>> pq;

    int mx = INT_MIN;

    // push first element of all k Arrays into the priority queue of size K

    for (int i = 0; i < n; i++)
    {
        pq.push({nums[i][0], {i, 0}}); // element , index of list , index of element

        mx = max(mx, nums[i][0]);
    }

    while (true)
    {
        pr currEle = pq.top();  // pop the element from pq it will be a minimum element
        pq.pop();

        int mn = currEle.first;

        if (range[1] - range[0] > mx - mn)  // check uf range can be updated or not
        {
            range[1] = mx;
            range[0] = mn;
        }

        int idx = currEle.second.second;   

        idx++;   // increment the index of popped element 


        int listIdx = currEle.second.first;

        vector<int> currList = nums[listIdx];   // we'll get to know which list we're working on 

        if (currList.size() == idx)   // check if the popped element is the last element 
        {
            break;    // we'll stop here as can't add more elements of a list 
        }

        else    // push the next element of the list in pq 
        {
            pq.push({currList[idx], {listIdx, idx}});
            mx = max(mx, currList[idx]);
        }
    }

    return range;
}

int main()
{

    return 0;
}