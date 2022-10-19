#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class CustomStack
{
private:
    unordered_map<int, int> map;
    stack<int> stack;
    int limit;

public:
    CustomStack(int maxSize)
    {
        limit = maxSize;
    }

    void push(int x)
    {
        if (stack.size() == limit)
        {
            return;
        }
        stack.push(x);
    }

    int pop()
    {
        if (stack.empty())
        {
            return -1;
        }

        int value = map[stack.size()]; // value we need to increase of this index

        map[stack.size()] = 0;         // after we increase, value of this index will set to 0

        int top = stack.top();
        stack.pop();

        map[stack.size()] += value; // If this index increase by value, so the bottom  of the index  will increase by value

        return top + value;
    }

    void increment(int k, int val)
    {
        k = min(k, (int)stack.size()); // Sometime k bigger than stack.size() so we use stack.size()
            
        map[k] += val;
    }
};

int main()
{

    return 0;
}