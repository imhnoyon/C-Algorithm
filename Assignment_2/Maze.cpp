#include <bits/stdc++.h>
using namespace std;
long long int n, m;
char mat[1005][1005];
bool vis[1005][1005];
map<pair<long long int, long long int>, pair<long long int, long long int>> p;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(long long int i, long long int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void bfs(long long int si, long long int sj)
{
    queue<pair<long long int, long long int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<long long int, long long int> par = q.front();
        long long int a = par.first, b = par.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            long long int ci = a + v[i].first;
            long long int cj = b + v[i].second;
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
    long long int si, sj;
    long long int di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'D')
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
        long long int u, v;
        u = di;
        v = dj;
        while (true)
        {
            if (mat[u][v] != 'R' && mat[u][v] != 'D')
            {
                mat[u][v] = 'X';
            }
            long long int nx = p[{u, v}].first;
            long long int ny = p[{u, v}].second;
            u = nx;
            v = ny;
            if (u == si && v == sj)
            {
                break;
            }
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
