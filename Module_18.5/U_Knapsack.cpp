#include <bits/stdc++.h>
using namespace std;
const int MaxN = 25;
const int MaxW = 105;
int dp[MaxN][MaxW];
int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n] <= W)
    {
        int op1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, W);

        // cout<<max(op1, op2);
        return dp[n][W] = max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = op2;
    }
}
int main()
{
    int n, W;
    cin >> n >> W;
    int weight[n + 1], value[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << knapsack(n, weight, value, W);
    return 0;
}
