#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() or maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            if (maxHeap.empty())
            {
                return 0;
            }
            else
            {
                double avg = (maxHeap.top() + minHeap.top()) / 2.0;
                return avg;
            }
        }

        else
        { 
            if (maxHeap.size() > minHeap.size())
            {
                return maxHeap.top();
            }
            else
            {
                return minHeap.top();
            }
        }
    }
};

int main()
{

    return 0;
}