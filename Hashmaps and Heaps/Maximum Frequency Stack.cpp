#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class FreqStack
{
public:
    unordered_map<int, stack<int>> st;
    unordered_map<int, int> freq;
    int maxFreq = 0;

    FreqStack()
    {
        st;
        freq;
        maxFreq = 0;
    }

    void push(int val)
    {
        int currFreq = 0;

        if (freq.find(val) != freq.end())
        {
            currFreq = freq[val];
        }
        else
        {
            currFreq = 0;
        }
        currFreq++;
        freq[val]++;

        st[currFreq].push(val);
        maxFreq = max(maxFreq, currFreq);
    }

    int pop()
    {
        int ans = st[maxFreq].top();
        st[maxFreq].pop();

        int currFreq = freq[ans];
        currFreq--;

        freq[ans] = currFreq;

        if (st[maxFreq].size() == 0)
        {
            st.erase(maxFreq);
            maxFreq--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}