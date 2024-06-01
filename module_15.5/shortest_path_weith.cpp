#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
vector<pair<int, int>> v[N];
int dis[N];
int par[N];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    par[N] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = node;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int src, des;
    cin >> src >> des;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 1; i < N; i++)
    {
        dis[i] = INT_MAX;
    }
    memset(par, -1, sizeof(par));

    dijkstra(src);

    if (par[des] == -1)
    {
        cout << "-1" << endl;
    }
    else
    {
        int x = des;
        cout << dis[des] << endl;
        vector<int> ans;
        while (x != -1)
        {
            ans.push_back(x);
            x = par[x];
        }
        reverse(ans.begin(), ans.end());
        for (int res : ans)
        {
            cout << res << " ";
        }
    }

    return 0;
}
