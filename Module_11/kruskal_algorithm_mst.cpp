#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
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
    if (parent[node] == -1)
        return node;
    else
    {
        int leader = find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}
void union_by_size(int node, int node2)
{
    int leaderA = find(node);
    int leaderB = find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    vector<Edge> edgelist;
    cin >> n >> e;
    dsu_initialize(n);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back(Edge(u, v, w));
    }
    sort(edgelist.begin(), edgelist.end(), cmp);
    int totalCost = 0;
    for (Edge ans : edgelist)
    {
        int leaderU = find(ans.u);
        int leaderV = find(ans.v);
        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            union_by_size(ans.u, ans.v);
            // cout << ans.u << " " << ans.v << endl;
            totalCost += ans.w;
        }
    }
    cout << totalCost << endl;
    // for (Edge ans : edgelist)
    // {
    //     cout << ans.u << " " << ans.v << " " << ans.w << endl;
    // }
    return 0;
}