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
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                v[i].push_back(j);
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(x);
    vector<int> v2;

    for (int i = 1; i <= n; i++)
    {
        cout << level[i] << " ";
    }

    // for (int ans : v2)
    // {
    //     cout << ans << " ";
    // }
    return 0;
}
