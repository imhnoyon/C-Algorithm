#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int par[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        level[i] = 0;
    }
}
int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    else
    {
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }
}
void union_by_level(int node, int node2)
{
    int leaderA = find(node);
    int leaderB = find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        level[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    dsu_initialize(7);
    union_by_level(1, 2);
    union_by_level(2, 3);
    union_by_level(3, 4);
    union_by_level(4, 5);
    union_by_level(1, 4);
    cout << find(1) << endl;
    cout << find(4) << endl;
    return 0;
}