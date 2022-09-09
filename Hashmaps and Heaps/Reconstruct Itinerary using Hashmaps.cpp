#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void reconstructItinearyUsingHashmaps(unordered_map<string, string> mp)
{
    unordered_map<string, bool> potentialSource;

    for (auto src : mp)
    {
        string source = src.first;
        string destination = src.second;

        potentialSource[destination] = false;

        if (potentialSource.find(source) == potentialSource.end())
        {
            potentialSource[source] = true;
        }
    }

    string source = "";

    for (auto it : potentialSource)
    {
        string src = it.first;
        bool value = it.second;

        if (value == true)
        {
            source = src;
            break;
        }
    }

    // print

    while (true)
    {
        if (mp.find(source) != mp.end())
        {
            cout << source << " -> ";

            source = mp[source];
        }

        else
        {
            cout << source << ".";
            break;
        }
    }
}

int main()
{
    return 0;
}