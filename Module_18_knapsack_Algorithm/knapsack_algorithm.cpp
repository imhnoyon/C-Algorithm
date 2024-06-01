#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int weith[], int value[], int W)
{

    if (n < 0 || W == 0)
        return 0;
    if (weith[n] < W)
    {
        // duita kaj
        int op1 = knapsack(n - 1, weith, value, W - weith[n]) + value[n];
        int op2 = knapsack(n - 1, weith, value, W);
        return max(op1, op2);
    }
    else
    {
        // ekta kaj
        int op2 = knapsack(n - 1, weith, value, W);
        return op2;
    }
}
int main()
{
    int n;
    cin >> n;
    int weith[n];
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weith[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int W;
    cin >> W;

    cout << knapsack(n - 1, weith, value, W);
    return 0;
}