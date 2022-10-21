#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class MaxStack
{
    stack<int> data;
    stack<int> maxVal;

public:
    MaxStack()
    {
    }

    void push(int x)
    {
        data.push(x);

        int m = x;

        if (maxVal.size() > 0)
        {
            int val = maxVal.top();
            m = max(val, m);
        }

        maxVal.push(m);
    }

    int pop()
    {
        maxVal.pop();

        int temp = data.top();
        data.pop();

        return temp;
    }

    int top()
    {
        return data.top();
    }

    int peekMax()
    {
        return maxVal.top();
    }

    int popMax()
    {
        int toBeRemoved = maxVal.top();

        stack<int> buffer;

        while (data.top() != toBeRemoved)
        {
            int res = pop();
            buffer.push(res);
        }

        pop();

        while(buffer.size() >0)
        {
            int res = buffer.top();
            buffer.pop();

            push(res);
        }

        return toBeRemoved;
    }
};
