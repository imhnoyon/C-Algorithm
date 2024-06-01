#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool vis[N];
int parent[N];
bool ans = false;
int cnt = 0;
void dfs(int s)
{

    // cout << s << " ";
    vis[s] = true;
    for (int child : v[s])
    {
        if (vis[child] == true && parent[s] != child)
        {
            ans = true;
            // cnt++;
        }
        if (vis[child] == false)
        {
            parent[child] = s;
            // vis[child]=true;
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
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    if (ans == true)
        cout << "Cycle Detected";
    else
        cout << "Cycle Not detected";
    return 0;
}