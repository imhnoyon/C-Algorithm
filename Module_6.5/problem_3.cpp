#include<bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
int level[100];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    int cnt=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child:v[par])
        {
          cnt++;
        }
    }
    cout<<cnt<<endl;
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
  int src;
  cin>>src;
  memset(vis,false,sizeof(vis));
  memset(level,-1,sizeof(level));
  bfs(src);
  return 0;
}