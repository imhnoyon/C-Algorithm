#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];
int level[1000];
vector<int>v2;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    int cnt=0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        
        for (int child : v[par])
        {
            cnt++;   
        }
    }
    cout<<cnt;
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
    int node;
    cin >> node;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(node);
    
    
    return 0;
}