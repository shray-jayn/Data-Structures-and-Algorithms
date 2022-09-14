#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m)
    {

        // case 1: both elements are equal
        if (arr1[i] == arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }

        // case 2: element 1 is smaller than element 2
        else if (arr1[i] < arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }

        // case 3: element 2 is smaller than element 1
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
    }

    // Edge Cases
    while (i < n)
    {
        if (ans.size() == 0 || ans.back() != arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if (ans.size() == 0 || ans.back() != arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }
    
    return ans;

}
int main()
{

    return 0;
}