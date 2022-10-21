#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a[] = {5, 7, 7, 8, 8, 10};
  int n = 7;
  int target = 7;

  int s = 0, e = n - 1, m, ans;

  while (s <= e)
  {
      m = s + (e - s) / 2;
      if (a[m] == target)
      {
          ans = m;
          e = m - 1;
      }

      else if (a[m] > target)
      {
          e = m - 1;
      }

      else
      {
          s = m + 1;
      }
  }

  cout << ans << endl;
  return 0;
  
}