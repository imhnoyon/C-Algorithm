#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u;
    int v;
    int w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n;
    cin >> n;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<edge> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > 0)
            {
                v.push_back(edge(i, j, mat[i][j]));
            }
        }
    }

    for (edge ed : v)
    {
        cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }

    return 0;
}