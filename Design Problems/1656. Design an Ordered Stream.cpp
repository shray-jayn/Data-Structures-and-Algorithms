#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class OrderedStream
{
public:
    int pointer = 0;
    vector<string> stream;

    OrderedStream(int n)
    {
        stream.resize(n);
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> ans;

        stream[idKey - 1] = value;

        while (pointer < stream.size() and stream[pointer] != "")
        {
            ans.push_back(stream[pointer]);
            pointer++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}