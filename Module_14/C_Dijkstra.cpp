#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
vector<pair<ll, ll>> v[N];
ll dis[N];
ll parent[N];
class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll s)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll parentnode = par.first;
        ll cost = par.second;
        for (pair<ll, ll> child : v[parentnode])
        {
            ll childNode = child.first;
            ll childcost = child.second;
            if (cost + childcost < dis[childNode])
            {
                dis[childNode] = cost + childcost;
                pq.push({childNode, dis[childNode]});
                parent[childNode] = parentnode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    dijkstra(1);
    int x = n;
    vector<int> v2;
    if (dis[n] == 1e18)
    {
        cout << "-1" << endl;
    }
    else
    {
        while (x != -1)
        {
            v2.push_back(x);
            x = parent[x];
        }
        reverse(v2.begin(), v2.end());
        for (int ans : v2)
        {
            cout << ans << " ";
        }
    }
    return 0;
}
