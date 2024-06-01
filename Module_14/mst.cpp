#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int group_size[N];
int parent[N];
class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
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
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<edge> v;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }

    sort(v.begin(), v.end(), cmp);
    int totalcost = 0;
    for (edge ed : v)
    {
        int leaderA = find(ed.u);
        int leaderB = find(ed.v);
        if(leaderA == leaderB)
        {
            continue;
        }
        else
        {
            union_by_size(ed.u,ed.v);
            totalcost+=ed.w;
        }
    }
    cout<<totalcost<<endl;
    return 0;
}