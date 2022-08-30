#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cout << t;
}
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cout << "{";
    _print(p.ff);
    cout << ",";
    _print(p.ss);
    cout << "}";
}
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    int n = routes.size();

    unordered_map<int, vector<int>> mp;

    // Generating a HAsh-Map

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < routes[i].size(); j++)
        {
            int busStopNumber = routes[i][j];

            if (mp.find(busStopNumber) != mp.end())
            {
                mp[busStopNumber].push_back(i);
            }

            else
            {
                vector<int> routeNum;
                routeNum.push_back(i);
                mp[busStopNumber] = routeNum;
            }
        }
    }

    // BFS

    queue<int> q;

    unordered_map<int, bool> busStopVis, busRouteVis;

    int level = 0;

    q.push(source);
    busStopVis[source] = true;

    while (q.size() > 0)
    {
        int size = q.size();

        while (size--)
        {

            int curr = q.front(); // current busStop

            if (curr == target)
            {
                return level;
            }

            q.pop();

            vector<int> buses = mp[curr]; // all the routes this busStop belongs to

            for (int bus : buses)
            {
                if (busRouteVis[bus] == false) // find bus route which is not visited
                {
                    vector<int> allStops = routes[bus];

                    for (auto h : allStops)
                    {
                        // check if current bus stop is visited or not

                        if (busStopVis[h] == false) // mark visited and push into queue
                        {
                            busStopVis[h] = true;
                            q.push(h);
                        }
                    }

                    // mark the route as visited

                    busRouteVis[bus] = true;
                }
            }
        }

        level++;
    }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};

    int ans = numBusesToDestination(routes, 1, 6);

    cout << ans << endl;
}