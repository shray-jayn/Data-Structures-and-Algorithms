#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1001][1001];

int solve(int health, int armour, int choice)
{
  if (health <= 0 or armour <= 0)
  {
    return 0;
  }

  if (dp[health][armour] != -1)
  {
    return dp[health][armour];
  }

  int fire = 0;
  int water = 0;
  int air = 0;

  if (choice != 1)  // if prev was not 1 we can go to 1 
  {
    fire = 1 + solve(health + 3, armour + 2, 1);
  }
  if (choice != 2)
  {
    water = 1 + solve(health - 5, armour - 10, 2);
  }
  if (choice != 3)
  {
    air = 1 + solve(health - 20, armour + 5, 3);
  }

  return dp[health][armour] = max({air, water, fire});
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int health, armour;

    cin >> health >> armour;

    memset(dp, -1, sizeof(dp));

    cout << max({solve(health + 3, armour + 2, 1), solve(health - 5, armour - 10, 2), solve(health - 20, armour + 5, 3)}) << endl;
  }

  return 0;
}