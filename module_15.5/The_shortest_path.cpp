#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int parent[N];
int level[N];
vector<int> v[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
                q.push(child);
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(src);
    vector<int> v2;
    int x = des;
    cout << level[des] << endl;
    while (x != -1)
    {
        // cout << x << " ";
        v2.push_back(x);
        x = parent[x];
    }

    sort(v2.begin(), v2.end());
    for (int ans : v2)
    {
        cout << ans << " ";
    }
    return 0;
}
