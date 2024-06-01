#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char mat[N][N];
bool vis[N][N];
int n, m;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < m && cj >= 0 && cj < n)
        return true;
    else
        return false;
}
int cnt;
void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;

    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;
        if (valid(ci, cj) == true && vis[ci][cj] == false && mat[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    int q;
    cin >> q;
    int s = 1;
    while (q--)
    {

        cin >> n >> m;
        int si, sj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }

        cnt = 0;
        memset(vis, false, sizeof(vis));
        dfs(si, sj);
        cout << "Case " << s++ << ": " << cnt << endl;
    }

    return 0;
}
