#include <bits/stdc++.h>
using namespace std;
int n, m;
int dis[100][100];
bool vis[100][100];
vector<pair<int, int>> v = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1}};
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
        pair<int, int> parent = q.front();
        int a = parent.first;
        int b = parent.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {

                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                q.push({ci, cj});
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
        int s, s2, d, d2;
        cin >> s >> s2;
        cin >> d >> d2;
        memset(vis, false, sizeof(vis));
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
        bfs(s, s2);

        if (vis[d][d2] == true)
        {
            cout << dis[d][d2] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
