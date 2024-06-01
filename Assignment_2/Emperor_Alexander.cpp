#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long int parent[N];
long long int group_size[N];
class Edge
{
public:
    long long int u, v;
    long long int w;
    Edge(long long int u, long long int v, long long int w)
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
void dsu_initialize(long long int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find(long long int node)
{
    if (parent[node] == -1)
        return node;
    long long int l = find(parent[node]);
    parent[node] = l;
    return l;
}
void union_by_size(long long int node, long long int node2)
{
    long long int lA = find(node);
    long long int lB = find(node2);
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
    long long int n, e;

    vector<Edge> edgelist;

    cin >> n >> e;
    int val = e;
    dsu_initialize(n);
    while (e--)
    {
        long long int u, v;
        long long int w;
        cin >> u >> v >> w;
        edgelist.push_back(Edge(u, v, w));
    }
    sort(edgelist.begin(), edgelist.end(), cmp);

    long long int count = 0;
    for (Edge ans : edgelist)
    {
        long long int lU = find(ans.u);
        long long int lV = find(ans.v);
        if (lU == lV)
        {
            continue;
        }
        else
        {
            union_by_size(ans.u, ans.v);
            totalSize += ans.w;
            count++;
        }
    }

    if (count != n - 1)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << val - count << " " << totalSize << endl;
    }

    return 0;
}