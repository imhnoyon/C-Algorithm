#include <bits/stdc++.h>
using namespace std;
int a[100][100];
bool vis[100][100];
int dis[100][100];
int n, m;

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

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
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
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

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int src1, src2, des1, des2;
        cin >> src1 >> src2 >> des1 >> des2;

          memset(vis, false, sizeof(vis));
        // memset(dis, -1, sizeof(dis));

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         vis[i][j] = false;
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dis[i][j] = -1;
            }
        }
      
        bfs(src1, src2);

        if (vis[des1][des2] == true)
        {
            cout << dis[des1][des2] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    // cout << dis[des1][des2];

    return 0;
}
