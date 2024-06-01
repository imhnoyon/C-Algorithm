#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
int level[100];
// int parent[100];
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
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                // parent[child] = par;
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
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        // memset(parent, -1, sizeof(parent));
        bfs(src);
        int x = des;
       
        if(level[x]==-1)
        {
            cout<<"-1"<<endl;
        }
       else
       {
          cout << level[x] << endl;
       }
        
    }
    return 0;
}
