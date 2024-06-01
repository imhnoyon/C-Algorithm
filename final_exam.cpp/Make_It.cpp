#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
bool knapsack(int initial, int n)
{
    if (initial == n)
    {
        return true;
    }
    if (initial >= n)
    {
        return false;
    }
    if (dp[initial] != -1)
    {
        return dp[initial];
    }
    bool op1 = knapsack(initial * 2, n);
    bool op2 = knapsack(initial + 3, n);

    return dp[initial] = op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
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