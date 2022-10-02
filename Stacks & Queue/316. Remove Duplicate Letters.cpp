#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string removeDuplicateLetters(string s)
{
    stack<char> st;

    vector<int> hash(26, 0);
    vector<bool> visited(26, false);

    for (auto u : s)
        hash[u - 'a']++;

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']--; // reduce frequency

        if (st.empty())
        {
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        else
        {
            if (!visited[s[i] - 'a']) // if not visited check the top element and freq of top element
            {
                while (!st.empty() and s[i] < st.top() and hash[st.top() - 'a'] != 0)
                {
                    visited[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(s[i]);              // push in stack
                visited[s[i] - 'a'] = true; // mark visited
            }
        }
    }

    string ans = "";

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}