#include<bits/stdc++.h>
#define ll long long
#define fastread()(ios_base::sync_with_stdio(0),cin.tie(0));
using namespace std;
const int N = 2002;
int n,m;
int maze[N][N],level[N][N],visited[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string direction;
 
pair<int,int>parent[N][N];
bool is_inside(pair<int,int>co)
{
    int x = co.first;
    int y = co.second;
    if(x>=0&&x<n&&y>=0&&y<m)
    {
        return true;
    }
    return false;
}
bool is_safe(pair<int,int>co)
{
    int x = co.first;
    int y = co.second;
    if(maze[x][y]==-1)
    return false;
    return true;
}
 
void bfs(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);
    parent[src.first][src.second] = {-1,-1};
    while(!q.empty())
    {
        pair<int,int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for(int i =0;i<4;i++)
        {
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            pair<int,int>adj_node;
            adj_node.first = new_x;
            adj_node.second = new_y;
            if(is_inside(adj_node)&&is_safe(adj_node)&&visited[new_x][new_y]==0)
            {
                parent[adj_node.first][adj_node.second] = {x,y};
                visited[new_x][new_y] = 1;
                level[new_x][new_y]=level[x][y]+1;
                q.push(adj_node);
 
            }
        }
 
    }
 
 
}
void path_print(pair<int,int>src,pair<int,int>dst)
{
    pair<int,int>selected_node = dst;
    while(true)
    {
        int x = selected_node.first;
        int y = selected_node.second;
        int x1 = parent[x][y].first;
        int y1 = parent[x][y].second;
        if(x>x1 && y==y1)
        {
            direction.push_back('D');
        }
        else if(x<x1 && y==y1)
        {
            direction.push_back('U');
        }
        else if(y>y1 && x==x1)
        {
            direction.push_back('R');
        }
        else if(y<y1 && x==x1)
        {
            direction.push_back('L');
        }
        if(selected_node == src)
        {
            break;
        }
 
        selected_node = parent[x][y];
    }
    reverse(direction.begin(),direction.end());
 
    cout<<direction<<"\n";
 
 
}
int main()
{
    fastread();
    cin>>n>>m;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            level[i][j]=-1;
        }
    }
    pair<int,int>src,dst;
    for(int i =0;i<n;i++)
    {
        string T;
        cin>>T;
        for(int j=0;j<m;j++)
        {
            if(T[j]=='#')
            maze[i][j]=-1;
            else if(T[j]=='A')
            {
                src.first=i;
                src.second=j;
            }
            else if(T[j]=='B')
            {
                dst.first=i;
                dst.second=j;
            }
 
        }
    }
    bfs(src);
    if(level[dst.first][dst.second]==-1)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        cout<<level[dst.first][dst.second]<<"\n";
        path_print(src,dst);
    }
    
    return 0;
 
}