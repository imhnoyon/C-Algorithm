#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[1005];
int dis[1005];
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
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        long long int cost = parent.second;
        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            long long int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    int src;
    cin >> src;
    int q;
    cin >> q;
    while (q--)
    {
        bool flag = false;
        long long int des, cost;
        cin >> des >> cost;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1e18;
        }
        dijkstra(src);
        for (int i = 1; i <= n; i++)
        {
            if (i == des && cost >= dis[i])
            {
                flag = true;
            }
            // cout << i << " -> " << dis[i] << endl;
        }
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}