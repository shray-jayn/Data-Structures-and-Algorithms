#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    int s, e, m;
    s = 0;
    e = n - 1;

    int startingIndex, endingIndex;

    while (s <= e)
    {
        m = s + (e - s) / 2;

        if (arr[m] == target && (m == 0 || arr[m - 1] != target))
        {
            startingIndex = m;
            cout << "Starting index is : " << m << endl;
            break;
        }
        else if (arr[m] < target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    if (s > e)
    {
        cout << "Element is not present!";
        return 0;
    }

    s = 0;
    e = n - 1;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (arr[m] == target && (m == n - 1 || arr[m + 1] != target))
        {
            endingIndex = m;
            cout << "Ending index is : " << m << endl;
            break;
        }
        else if (arr[m] <= target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    cout << "Number of such elements are : " << endingIndex - startingIndex + 1;
}