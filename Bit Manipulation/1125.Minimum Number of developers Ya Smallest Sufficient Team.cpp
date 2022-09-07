#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
{
    vector<int> mask(people.size(), 0);

    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < req_skills.size(); j++)
        {
            for (int z = 0; z < people[i].size(); z++)
            {
                if (people[i][z] == req_skills[j])
                {
                    mask[i] += mask[i] << j;
                    break;
                }
            }
        }
    }


    



        
}

int main()
{
    return 0;
}