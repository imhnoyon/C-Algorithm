#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int dis[N];
int parent[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1;
                parent[child] = par;
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    int x = n;
    int cnt = 0;
    vector<int> v2;
    while (x != -1)
    {
        cnt++;
        v2.push_back(x);
        x = parent[x];
    }

    sort(v2.begin(), v2.end());
    if (v2.size() == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << cnt << endl;
        for (int ans : v2)
        {
            cout << ans << " ";
        }
    }

    return 0;
}