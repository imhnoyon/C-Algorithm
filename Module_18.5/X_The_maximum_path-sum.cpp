#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mat[15][15];
ll dp[15][15];
int n, m;
ll max_sum(int i, int j)
{
    if (i == n - 1 && j == m - 1)
        return mat[i][j];
    if (i >= n || j >= m)
        return INT_MIN;
    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    ll op1 = max_sum(i + 1, j);
    ll op2 = max_sum(i, j + 1);

    return dp[i][j] = max(op1, op2) + mat[i][j];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    cout << max_sum(0, 0) << endl;

    return 0;
}
