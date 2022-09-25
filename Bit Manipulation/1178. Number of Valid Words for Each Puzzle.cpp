#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    int n = words.size();
    int m = puzzles.size();

    unordered_map<char, vector<int>> mp;

    // Generate an empty Map

    for (int i = 0; i < 26; i++)
    {
        mp[i + 'a'].push_back({});
    }

    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        string word = words[i];

        // generate mask for each word

        for (int j = 0; j < words[i].size(); j++)
        {
            char ch = word[j];
            int bit = ch - 'a';

            mask = (mask | (1 << bit));
        }

        //  put the word into the map and use set to avoid multiple adding of same word 

        unordered_set<char> unique;

        for (int j = 0; j < words[i].size(); j++)
        {
            char ch = word[j];

            if (unique.find(ch) != unique.end())
            {
                continue;   
            }
            unique.insert(ch);

            mp[ch].push_back(mask);
        }
    }

    vector<int> result;

    // Iterate through all the puzzles!

    for (int i = 0; i < m; i++)
    {

        int puzzleMask = 0;
        string puzzle = puzzles[i];

        // generate mask for each puzzle

        for (int j = 0; j < puzzle.size(); j++)
        {
            char ch = puzzle[j];
            int bit = ch - 'a';

            puzzleMask = (puzzleMask | (1 << bit));
        }

        char firstChar = puzzle[0];

        vector<int> wordsToCheck = mp[firstChar]; // get all the corresponding words
        int count = 0;

        for (auto it : wordsToCheck)
        {
            int wordMask = it;

            // Check if all char of word are in puzzle

            if ((wordMask & puzzleMask) == wordMask)
            {
                count++;
            }
        }

        result.push_back(count);
    }

    return result;
}

int main()
{

    return 0;
}