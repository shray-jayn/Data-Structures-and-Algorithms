#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> nearestSmallestLeft(ll arr[], int n)
{
  vector<ll> ans;

  stack<pair<ll, ll>> st;

  for (int i = 0; i < n; i++)
  {
    if (st.size() == 0)
    {
      ans.push_back(-1);
    }

    if (st.size() > 0 and st.top().first < arr[i])
    {
      ans.push_back(st.top().second);
    }

    else if (st.size() > 0 and st.top().first >= arr[i])
    {
      while (st.size() > 0 and st.top().first >= arr[i])
      {
        st.pop();
      }
      if (st.size() == 0)
      {
        ans.push_back(-1);
      }
      else
      {
        ans.push_back(st.top().second);
      }
    }

    st.push({arr[i], i});
  }

  return ans;
}

vector<ll> nearestSmallestRight(ll arr[], int n)
{
  vector<ll> ans;

  stack<pair<ll, ll>> st;

  for (int i = n - 1; i >= 0; i--)
  {
    if (st.size() == 0)
    {
      ans.push_back(n);
    }

    if (st.size() > 0 and st.top().first < arr[i])
    {
      ans.push_back(st.top().second);
    }

    else if (st.size() > 0 and st.top().first >= arr[i])
    {
      while (st.size() > 0 and st.top().first >= arr[i])
      {
        st.pop();
      }
      if (st.size() == 0)
      {
        ans.push_back(n);
      }
      else
      {
        ans.push_back(st.top().second);
      }
    }

    st.push({arr[i], i});
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

long long
getMaxArea(long long arr[], int n)
{
  // Your code here

  vector<ll> left = nearestSmallestLeft(arr, n);

  vector<ll> right = nearestSmallestRight(arr, n);

  vector<ll> width;
  for (int i = 0; i < n; i++)
  {
    ll a = right[i] - left[i] - 1;
    width.push_back(a);
  }

  vector<ll> area;

  ll maxArea = LONG_LONG_MIN;

  for (int i = 0; i < n; i++)
  {
    ll a = arr[i] * width[i];
    maxArea = max(maxArea, a);
    area.push_back(a);
  }

  return maxArea;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    cout << getMaxArea(arr, n) << endl;
  }
}