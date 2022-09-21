#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int wineTrading(vector<int> &arr)
{
  int n = arr.size();
  vector<pair<int, int>> buy;
  vector<pair<int, int>> sell;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      sell.push_back({arr[i], i});
    }
    else
    {
      buy.push_back({arr[i], i});
    }
  }

  int ans = 0;
  int i = 0;
  int j = 0;

  while (i < buy.size() and j < sell.size())
  {
    int x = min(buy[i].first, -sell[i].first);

    buy[i].first -= x;
    sell[i].first -= x;

    int diff = abs(buy[i].second - sell[j].second);
    ans += x * diff;

    if (buy[i].first == 0)
    {
      i++;
    }
    else if (sell[j].first == 0)
    {
      j++;
    }
  }

  return ans;
}

int main()
{

  return 0;
}