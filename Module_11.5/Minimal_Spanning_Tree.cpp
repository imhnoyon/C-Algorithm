#include <bits/stdc++.h>
// #define ll long long int
using namespace std;
int parent[20005];
long long int group_size[20005];
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
    int l = find(parent[node]);
    parent[node] = l;
    return l;
}
void union_by_size(int node, int node2)
{
    int lA = find(node);
    int lB = find(node2);
    if (group_size[lA] > group_size[lB])
    {
        parent[lB] = lA;
        group_size[lA] += group_size[lB];
    }
    else
    {
        parent[lA] = lB;
        group_size[lB] += group_size[lA];
    }
}
int main()
{

    long long int totalSize = 0;
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
    for (Edge ans : edgelist)
    {
        int lU = find(ans.u);
        int lV = find(ans.v);
        if (lU == lV)
        {
            continue;
        }
        else
        {
            union_by_size(ans.u, ans.v);
            totalSize += ans.w;
        }
    }
    cout << totalSize << endl;
    return 0;
}