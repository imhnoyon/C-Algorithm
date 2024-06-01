#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m;
char mat[N][N];
pair<int, int> path[N][N];
bool vis[N][N];

bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int si, int sj)
{
    vis[si][sj] = true;
    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        int pi = q.front().first;
        int pj = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                path[ci][cj] = {pi, pj};
                q.push({ci, cj});
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
                di = i;
                dj = j;
            }
            if (mat[i][j] == 'R')
            {
                si = i;
                sj = j;
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

        int x = di, y = dj;

        while (x != si || y != sj)
        {
            if (mat[x][y] != 'R' && mat[x][y] != 'D')
            {
                mat[x][y] = 'X';
            }
            pair<int, int> pr = path[x][y];

            x = pr.first;
            y = pr.second;
            // cout<<x <<" "<<y<<endl;
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
