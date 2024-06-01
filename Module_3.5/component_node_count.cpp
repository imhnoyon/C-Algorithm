#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
int cnt = 0;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (int child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
            vis[child] = true;
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
    // int count = 0;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        if (vis[i] == false)
        {
            dfs(i);
            // cout << cnt << " ";
            v2.push_back(cnt);
        }
    }
    sort(v2.begin(),v2.end());
    for(int ans:v2)
    {
        cout<<ans<<" ";
    }

    return 0;
}