#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int par[N];
int cnt = 0;
void dfs(int s)
{
    vis[s] = true;
    for (int child : v[s])
    {
        if (vis[child] && par[s] != child)
        {
            cnt++;
        }
        if (!vis[child])
        {
            par[child] = s;
            dfs(child);
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
    memset(par, -1, sizeof(par));

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    int val = (cnt / 2);
    cout << val << endl;
    return 0;
}