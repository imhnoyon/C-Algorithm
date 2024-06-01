#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> mp;
bool subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (mp.find({n, s}) != mp.end())
    {
        return mp[{n, s}];
    }
    if (a[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, a, s - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, s);
        return mp[{n, s}] = op1 || op2;
    }
    else
    {
        bool op2 = subset_sum(n - 1, a, s);
        return mp[{n, s}] = op2;
    }
}
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum=1000-s;
    bool ans = subset_sum(n, a, sum);
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}