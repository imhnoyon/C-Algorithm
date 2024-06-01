#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1005][1005];
bool vis[1005][1005];
map<pair<int, int>, pair<int, int>> p;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                // dis[ci][cj] = {a, b};
                p[{ci, cj}] = {a, b};
            }
        }
    }
}
int main()
{
    int si, sj;
    int di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'D')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'R')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(si, sj);

    if (!vis[di][dj])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        int u, v;

        while (true)
        {

            u = p[{di, dj}].first;
            v = p[{di, dj}].second;
            di = u;
            dj = v;
            if (di != si && dj != sj)
            {
                break;
            }
            if (mat[u][v] != 'R' && mat[u][v] != 'D')
            {
                mat[u][v] = 'X';
            }

            // cout << u << " " << v << endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}