#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int unbounded_knapsack(int n, int w, int val[], int weight[])
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n - 1] <= w)
    {
        int op1 = unbounded_knapsack(n, w - weight[n - 1], val, weight)+val[n - 1];
        int op2 = unbounded_knapsack(n - 1, w, val, weight);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        return dp[n][w] = unbounded_knapsack(n - 1, w, val, weight);
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int value[n], weight[n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << unbounded_knapsack(n, w, value, weight);
    return 0;
}