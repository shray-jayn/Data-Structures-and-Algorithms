#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void helper(int start, int level, int sum, vector<int> &combination, vector<vector<int>> &combinations)
{

    // base comdition
    if (level == 0)
    {
        if (sum == 0)
        {
            combinations.push_back(combination);
            for (int i = 0; i < combination.size(); i++)
            {
                cout << combination[i] << " ";
            }
            cout << endl;
        }

        return;
    }

    if (start > 9 or sum < 0)
    {
        return;
    }

    // recursive code

    for (int i = start; i <= 9; i++)
    {
        combination.push_back(i);
        helper(i + 1, level - 1, sum - i, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;
    vector<int> arr;

    helper(1, k, n, arr, result);

    return result;
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<vector<int>> result = combinationSum3(k, n);

    return 0;
}