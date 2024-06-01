#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
int level[100];
int cnt=0;
void dfs(int src)
{
    // cout<<src<<endl;
    cnt++;
    vis[src]=true;
    level[src]=0;
    for(int child:v[src])
    {
        if(vis[child]==false)
        {
            dfs(child);
            vis[child]=true;
            
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
    int src;
    cin >> src;
    memset(vis,false,sizeof(vis));
    dfs(src);
    cout<<cnt<<endl;
    
    return 0;
}