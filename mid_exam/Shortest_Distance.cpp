#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll mat[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mat[i][j] = 1e18;
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        int mn = (min(mat[a][b], c));
        mat[a][b] = mn;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mat[i][k] != 1e18 && mat[k][j] != 1e18 && mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll src, dis;
        cin >> src >> dis;
        // cout << mat[src][dis] << endl;
        if (mat[src][dis] != 1e18)
        {
            cout << mat[src][dis] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}