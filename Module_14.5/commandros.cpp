#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
bool vis[N];
int dis[N];
int des[N];
void bfs(int s, int track)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    if (track == 1)
    {
        dis[s] = 0;
    }
    else
    {
        des[s] = 0;
    }
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
                if (track == 1)
                {
                    dis[child] = dis[par] + 1;
                }
                else
                {
                    des[child] = des[par] + 1;
                }
            }
        }
    }
}
int main()
{
    int q;
    cin >> q;
    int s = 1;
    while (q--)
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
        int src, d;
        cin >> src >> d;
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            dis[i] = -1;
        }
        bfs(src, 1);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            des[i] = -1;
        }
        bfs(d, 2);
        int result = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int value = dis[i] + des[i];
            result = max(value, result);
        }
        cout << "Case " << s++ << ": " << result << endl;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}