#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find(int node)
{
    if (parent[node])
        return node;
    else
    {
        int leader = find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}
void union_by_size(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    dsu_initialize(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            union_by_size(a, b);
        }
    }
    if (cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Detected" << endl;

    return 0;
}
