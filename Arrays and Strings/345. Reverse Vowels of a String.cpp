#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isvowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

string reverseVowels(string s)
{
    int n = s.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {

        while (left < right && !isvowel(s[left]))
            left++;
        while (left < right && !isvowel(s[right]))
            right--;
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main()
{

    return 0;
}