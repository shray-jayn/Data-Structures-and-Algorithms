#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long solve(int x, int y, int n, long hash[][4][3])
{
    // checking whether the postion is a valid postion or not
    if (x < 0 || y < 0 || x >= 4 || y >= 3 || (x == 3 && y == 0) || (x == 3 && y == 2))
    {
        return 0;
    }
    if (n == 1) // if n==1 then we can only move 1 step so return the same
    {
        return 1;
    }
    if (hash[n][x][y] > 0) // taking hash as 3D array which helps to store previous result
    {
        // if it exists we can just return the same
        return hash[n][x][y];
    }
    int mod = 1000000007; // to make sure that our answer is in range
    /*
                this below step is crucial one because we have only
                8 direction's to move to any other cell/in keypad so
                just check that below one you can get a clear cut note \
                what i was doing ;;
                just take a paper and pen and try to observe the step's
                you can get it easily'''
    */
    long ans = solve(x - 1, y + 2, n - 1, hash) % mod +
               solve(x + 1, y + 2, n - 1, hash) % mod +
               solve(x - 1, y - 2, n - 1, hash) % mod +
               solve(x + 1, y - 2, n - 1, hash) % mod +
               solve(x + 2, y + 1, n - 1, hash) % mod +
               solve(x + 2, y - 1, n - 1, hash) % mod +
               solve(x - 2, y + 1, n - 1, hash) % mod +
               solve(x - 2, y - 1, n - 1, hash) % mod;
    hash[n][x][y] = ans;

    return ans % mod;
}
int knightDialer(int n)
{
    long hash[n + 1][4][3];
    memset(hash, 0, sizeof(hash)); // making the arr to zeroes
    long ans = 0;
    int mod = 1000000007;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = (ans + solve(i, j, n, hash)) % mod; // calculating answere for every cell
        }
    }
    return (ans) % mod;
}w

int main()
{

    return 0;
}