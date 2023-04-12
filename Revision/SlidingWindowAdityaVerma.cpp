#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// FIXED SIZE SLIDING WINDOW

// Maximum sum subarray of size k

int maximumSumSubarray(int k, vector<int> &arr, int n)
{
  int sum = 0;
  int maxSum = INT_MIN;

  int i = 0, j = k;

  for (i = 0; i < k; i++)
  {
    sum += arr[i];
  }

  maxSum = max(sum, maxSum);

  // i == j == k

  while (j < n)
  {
    sum += arr[j];
    j++;
    sum -= arr[i];
    i++;

    maxSum = max(maxSum, sum);
  }

  return maxSum;
}

// First negative number in every window of size k

vector<int> printFirstNegativeInteger(vector<int> &arr, int n, int k)
{
  queue<int> q;
  vector<int> ans;

  int i = 0;
  int j = k;

  for (i = 0; i < k; i++)
  {
    if (arr[i] < 0)
    {
      q.push(arr[i]);
    }
  }

  if (q.size() == 0)
  {
    ans.push_back(0);
  }
  else
  {
    ans.push_back(q.front());
  }

  while (j < n)
  {
    if (arr[j] < 0)
    {
      q.push(arr[j]);
    }
    j++;

    if (q.front() == arr[i])
    {
      q.pop();
    }
    i++;

    if (q.size() == 0)
    {
      ans.push_back(0);
    }
    else
    {
      ans.push_back(q.front());
    }
  }

  return ans;
}

// String anagram ( Count occourance )

int countOcc(string pat, string txt)
{
  int k = pat.size();
  int n = txt.size();

  unordered_map<int, int> mp;

  for (int i = 0; i < k; i++)
  {
    mp[pat[i]]++;
  }

  int count = mp.size();

  int i = 0, j = 0;

  int ans = 0;

  while (j < 0)
  {
    char ch = txt[j];

    if (mp.find(ch) != mp.end())
    {
      mp[ch]--;

      if (mp[ch] == 0)
      {
        count--;
      }
    }

    // window size == k

    if (j - i + 1 < k)
    {
      j++;
    }

    else if (j - i + 1 == k)
    {

      if (count == 0)
      {
        ans += 1;
      }

      // shrink and update

      char ch = txt[i];

      if (mp.find(ch) != mp.end())
      {
        mp[ch] += 1;

        if (mp[ch] == 1)
        {
          count++;
        }
      }

      j++;
      i++;
    }
  }

  return ans;
}

// Maximum sliding window of size k

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  int n = nums.size();

  int i = 0;
  int j = 0;

  deque<int> dq;
  vector<int> result;

  while (j < n)
  {
    dq.push_back(nums[j]);

    if (j - i + 1 < k)
    {
      j++;
    }

    else if (j - i + 1 == k)
    {
      i++;
      j++;
    }
  }

  return result;
}

// VARIABLE SIZE SLIDING WINDOW

int main()
{

  return 0;
}