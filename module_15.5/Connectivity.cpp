#include <bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N];
vector<int> v[N];
int cnt = 0;
void dfs(int s)
{
    vis[s] = true;
    cnt++;
    for (int child : v[s])
    {
        if (!vis[child])
        {
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

    dfs(1);

    if (n == cnt)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}