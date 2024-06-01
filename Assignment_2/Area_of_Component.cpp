#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
int n, m;
bool vis[1000][1000];
int cnt = 0;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}
void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;

    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] != '-')
        {
            dfs(ci, cj);
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
    vector<int> v;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && a[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                // cout<<cnt<<" ";
                v.push_back(cnt);
            }
        }
    }
    int mn = INT_MAX;
    if (!v.empty())
    {
        sort(v.begin(), v.end());
        for (int ans : v)
        {
            mn = min(ans, mn);
        }
        cout << mn;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
