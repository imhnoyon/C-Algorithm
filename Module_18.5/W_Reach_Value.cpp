#include <bits/stdc++.h>
using namespace std;
map<long long int, bool> mp;
bool knapsack(long long int initial, long long int n)
{
    if (initial == n)
    {
        return true;
    }
    if (initial > n)
    {
        return false;
    }
    if (mp.find(initial) != mp.end())
    {
        return mp[initial];
    }
    bool op1 = knapsack(initial * 10, n);
    bool op2 = knapsack(initial * 20, n);
    return mp[initial] = op1 || op2;
    // return op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        mp.clear();
        bool val = knapsack(1, n);
        if (val == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}