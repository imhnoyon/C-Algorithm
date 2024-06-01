#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool vis[N];
bool pathvis[N];
bool ans = false;
void dfs(int parent)
{
    vis[parent] = true;
    pathvis[parent] = true;
    for (int child : v[parent])
    {
        if (pathvis[child] == true)
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
    pathvis[parent] = false;
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
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }

    if (ans)
        cout << "Cycle Detected";
    else
        cout << "Cycle Not Detected";
    return 0;
}