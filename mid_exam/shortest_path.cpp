#include <bits/stdc++.h>
using namespace std;
vector<int> v[20];
bool vis[20][20];
int dis[20][20];
int a[20][20];
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
vector<pair<int, int>> v2 = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ci = a + v2[i].first;
            int cj = b + v2[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                // cout<<ci<<" "<<cj<<endl;
                cout << dis[ci][cj] << endl;
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         vis[i][j] = false;
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         dis[i][j] = -1;
    //     }
    // }
    bfs(si, sj);
    // cout << a[5][4];

    return 0;
}