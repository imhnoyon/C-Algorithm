#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool vis[100005];
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
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> d;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            d.push_back(i);
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    // for (int ans : d)
    // {
    //     cout << ans <<" ";
    // }

    for (int i = 0; i < d.size() - 1; i++)
    {
        cout << d[i] << " " << d[i + 1] << endl;
    }
    return 0;
}
