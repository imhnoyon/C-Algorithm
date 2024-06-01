#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, c;
    edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 105;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> v;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (edge ed : v)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << "30000"
                 << " ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }
    return 0;
}