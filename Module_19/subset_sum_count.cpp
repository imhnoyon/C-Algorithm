#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int subset(int n, int a[], int s)
{

    if (n == 0)
    {
        if (s == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (a[n - 1] <= s)
    {
        int op1 = subset(n - 1, a, s - a[n - 1]);
        int op2 = subset(n - 1, a, s);
        return dp[n][s] = op1 + op2;
    }
    else
    {
        return dp[n][s] = subset(n - 1, a, s);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = subset(n, a, s);
    cout << ans << endl;
    return 0;
}
