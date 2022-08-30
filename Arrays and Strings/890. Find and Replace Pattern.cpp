#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isMatching(string &word, string &pattern)
{
    int n = word.size();

    unordered_map<char, char> mp; // patternChar , wordChar
    unordered_set<char> st;   // wordChar

    for (int i = 0; i < n; i++)
    {
        char wordChar = word[i];
        char patternChar = pattern[i];

        if (mp.find(patternChar) != mp.end()) // check if it is alrealy mapped
        {
            if (mp[patternChar] != wordChar)
            {
                return false;
            }
        }
        else
        {   
            if(st.find(wordChar) != st.end())   // checks if set contains that wordChar or not 
            {
                return false ;
            }
            mp[patternChar] = wordChar;  // add in map 
            st.insert(wordChar);  // add in set 
        }
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> res;

    for (auto word : words)
    {
        if (isMatching(word, pattern))
        {
            res.push_back(word);
        }
    }

    return res;
}

int main()
{

    return 0;
}