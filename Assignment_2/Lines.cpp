#include <bits/stdc++.h>
using namespace std;
int n;
char mat[1005][1005];
bool vis[1005][1005];
// pair<int, int> dis[1005][1005];
map<pair<int, int>, pair<int, int>> p;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
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
            if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] != 'O')
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '@')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'X')
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
        cout << "N" << endl;
    }
    else
    {
        int u, v;
        u = di;
        v = dj;
        while (true)
        {
            mat[u][v] = '+';
            int nx = p[{u, v}].first;
            int ny = p[{u, v}].second;
            u = nx;
            v = ny;
            if (u == si && v == sj)
            {
                break;
            }

        }
        cout << "Y" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}