#include <bits/stdc++.h>
using namespace std;
int n;
char mat[31][31];
bool vis[31][31];
int dis[31][31];
vector<pair<int, int> > v ;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    else
        return true;
}
int cnt = 0;
void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    v.push_back({0,1});
    v.push_back({0,-1});
    v.push_back({1,0});
    v.push_back({-1,0});
    while (cin >> n)
    {

        int di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 'S')
                {

                    bfs(i, j);
                }
            }
        }

        cout << dis[di][dj];
        cout << endl;
    }
    return 0;
}