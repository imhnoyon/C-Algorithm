#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dis[N];
vector<int> v[N];
bool vis[N];
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
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1;
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
    memset(dis, -1, sizeof(dis));
    memset(vis, false, sizeof(vis));
    int src, d, step;
    cin >> src >> d >> step;
    bfs(src);

    if (dis[d] != -1 && dis[d] <= step * 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

