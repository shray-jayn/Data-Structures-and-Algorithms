#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string complexNumberMultiply(string num1, string num2)
{
    // num1 = a+bi
    // num2 = c+di
    // res = (a*c - b*d) +(a*d +c*b)i

    int a = stoi(num1.substr(0, num1.find('+')));
    int b = stoi(num1.substr(num1.find('+') + 1, num1.size() - 1));
    int c = stoi(num2.substr(0, num2.find('+')));
    int d = stoi(num2.substr(num2.find('+') + 1, num2.size() - 1));

    // cout << a << " " << b << " " << c << " " << d << endl;

    string realPart = to_string(a * c - b * d);
    string imaginaryPart = to_string(a * d + c * b);

    string ans = "";

    ans = realPart + "+" + imaginaryPart + "i";

    return ans;
}
int main()
{
    string a, b;
    cin >> a >> b;

    cout << complexNumberMultiply(a, b) << endl;

    return 0;
}