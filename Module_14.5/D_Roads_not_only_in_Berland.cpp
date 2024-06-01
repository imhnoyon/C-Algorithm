#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
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
int main()
{
    int n;
    cin >> n;
    dsu_initialize(n);
    vector<pair<int, int>> v;
    vector<pair<int, int>> v2;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int lA = find(a);
        int lB = find(b);
        if (lA == lB)
        {
            v.push_back({a, b});
        }
        else
        {
            union_by_size(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int lA = find(1);
        int lB = find(i);
        if (lA != lB)
        {
            union_by_size(1, i);
            v2.push_back({1, i});
        }
    }

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << " " << v2[i].first << " " << v2[i].second << endl;
    }

    return 0;
}