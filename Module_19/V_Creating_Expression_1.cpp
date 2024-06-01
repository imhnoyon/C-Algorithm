#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<long long int, long long int>, long long int> mp;
bool subset(ll n, ll ar[], ll t)
{
    if (n == 0)
    {
        if (t == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (mp.find({n, t}) != mp.end())
    {
        return mp[{n, t}];
    }
    bool op1=false, op2;
    if (n != 1)
    {
        op1 = subset(n - 1, ar, t + ar[n - 1]);
    }
    op2 = subset(n - 1, ar, t - ar[n - 1]);
    return mp[{n, t}] = op2 || op1;
}
int main()
{
    ll n, t;
    cin >> n >> t;
    ll ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    bool ans = subset(n, ar, t);
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}