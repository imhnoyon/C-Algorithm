#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
bool vis[100];
int level[100];
int parent[100];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();

        for(auto child:v[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
                parent[child]=par;
            }
        }
    }
}

int main()
{
  int n,e;
  cin>>n>>e;
  while(e--)
  {
     int a,b;
     cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int src,des;
  cin>>src>>des;
  memset(vis,false,sizeof(vis));
  memset(level,-1,sizeof(level));
  memset(parent,-1,sizeof(parent));
  bfs(src);
  int x=des;
  vector<int> res;

   while(x != -1)
   {
      res.push_back(x);
      x=parent[x];
   }
   reverse(res.begin(),res.end());
   for(int ans:res)
   {
      cout<<ans<<" ";
   }
  return 0;
}