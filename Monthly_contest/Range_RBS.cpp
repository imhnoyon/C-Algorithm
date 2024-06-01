#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int> v[100005];
bool ans = true;
int dis[100005];

void dfs(int src)
{
    vis[src] = true;
    for (int child : v[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n;
    char ar[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> ar[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
      

        dfs(src);

    }
    return 0;
}