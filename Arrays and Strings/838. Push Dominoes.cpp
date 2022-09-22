#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solveConfig(vector<char> arr, int &i, int &j)
{
  if (arr[i] == 'L' and arr[j] == 'L') // make all L
  {
    for (int k = i + 1; k < j; k++)
    {
      arr[i] = 'L';
    }
  }

  else if (arr[i] == 'R' and arr[j] == 'R') // Make all R
  {
    for (int k = i + 1; k < j; k++)
    {
      arr[i] = 'R';
    }
  }

  else if (arr[i] == 'L' and arr[j] == 'R') // Do nothing
  {
  }
  
  else if (arr[i] == 'R' and arr[j] == 'L') // solve acc. to Odd or Even count
  {
    int diff = j - i;
    int mid = (i + j) / 2;

    if (diff % 2 != 0) // EVEN
    {
      for (int k = i + 1; k < mid; k++)
      {
        arr[i] = 'R';
      }
      for (int k = mid + 1; k < j; k++)
      {
        arr[i] = 'L';
      }
    }
    else // ODD
    {
      for (int k = i + 1; k <= mid; k++)
      {
        arr[i] = 'R';
      }
      for (int k = mid + 1; k < j; k++)
      {
        arr[i] = 'L';
      }
    }
  }
}

string pushDominoes(string dominoes)
{
  int n = dominoes.size();

  vector<char> arr(n + 2);

  int m = n + 2;

  arr[0] = 'L';
  arr[n + 1] = 'R';

  for (int i = 1; i < n + 1; i++)
  {
    arr[i] = dominoes[i - 1];
  }

  for (int i = 0; i < m; i++)
  {
    cout << arr[i];
  }
  cout << endl;

  int j = 0;
  int k = 1;

  while (k < m)
  {
    while (arr[k] == '.')
    {
      k++;
    }
    if (k - j > 1)
    {
      cout<<j<<arr[j]<<"-"<<k<<arr[k]<<endl;

      solveConfig(arr, j, k);

      for(int i = j ;i<= k ;i++)
      {
        cout<<arr[i];
      }
      cout<<endl;

    }
    j = k;
    k++;
  }

  string res = "";
  for (int i = 1; i < m - 1; i++)
  {
    res += arr[i];
  }
  cout << endl;
  cout << endl;
  return res;
}

int main()
{
  string s;
  cin >> s;

  cout << pushDominoes(s) << endl;

  return 0;
}