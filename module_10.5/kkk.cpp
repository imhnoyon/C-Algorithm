#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
bool vis[1000][1000];
int dis[1000][1000];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
bool res;
void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;

    if (a[si][sj] == 'B')
    {
        res = true;
    }

    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] != '#')
        {

            dis[ci][cj] = dis[si][sj] + 1;
            dfs(ci, cj);
        }
    }
}
void path_print(int si, int sj)
{
    int ci, cj;
    for (int i = 0; i < 4; i++)
    {
        ci = si + d[i].first;
        cj = sj + d[i].second;
        if (a[sj] < a[cj] && a[si] == a[ci])
        {
            cout << "L";
        }
        else if (a[si] < a[ci] && a[sj] == a[cj])
        {
            cout << "D";
        }
        else if (a[sj] > a[cj] && a[si] == a[ci])
        {
            cout << "R";
        }
        else if (a[si] > a[ci] && a[sj] == a[cj])
        {
            cout << "U";
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
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                dfs(i, j);
                if (res == true)
                {
                    cout << "YES" << endl;
                }
                else if (res == false)
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'B')
            {
                cout << dis[i][j] << endl;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                path_print(i, j);
            }
        }
    }
    return 0;
}
