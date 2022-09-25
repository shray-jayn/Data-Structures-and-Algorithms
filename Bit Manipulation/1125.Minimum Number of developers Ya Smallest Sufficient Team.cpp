#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> solution;

void helper(vector<int> &skillMap, int nSkills, int currPerson, vector<int> tempSol, int skillMask)
{

    if (currPerson == skillMap.size())
    {
        if (skillMask == (1 << nSkills) - 1) // check if all skills are 1
        {
            if (solution.size() == 0 or tempSol.size() < solution.size()) // ya to pehla solution hai ya purane wale se badiya hai
            {
                solution = tempSol;
            }
        }

        return;
    }

    // doesn't want to join
    helper(skillMap, nSkills, currPerson + 1, tempSol, skillMask);

    // wants to join

    tempSol.push_back(currPerson);

    skillMask = (skillMask | skillMap[currPerson]); // OR kar denge

    helper(skillMap, nSkills, currPerson + 1, tempSol, skillMask);

    tempSol.pop_back(); // backtrack
}

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
                    mask[i] += (1 << j);
                    break;
                }
            }
        }
    }

    vector<int> temp;

    helper(mask, req_skills.size(), 0, temp, 0);

    return solution;
}
int main()
{
    return 0;
}