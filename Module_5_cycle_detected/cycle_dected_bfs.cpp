#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int parent[N];
bool ans = false;
// int val=-1;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout<<par<<endl;

        for (int child : v[par])
        {
            if (vis[child] == true && parent[par] != child)
            {
                // val=child;
                ans = true;
                // break;
                //    cout<<child<<endl;
            }
            if (!vis[child])
            {
                vis[child] = true;
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
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (ans)
    {
        cout << "Cycle Ache" << endl;
    }
    else
    {
        cout << "Cycle Nei";
    }
    return 0;
}
