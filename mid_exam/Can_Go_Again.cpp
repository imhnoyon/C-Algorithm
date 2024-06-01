#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1005;
long long int dis[N];
int main()
{
    vector<Edge> EdgeList;
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        long long int c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
    }
    int src;
    cin >> src;
    dis[src] = 0;

    int q;
    cin >> q;
    while (q--)
    {
        int d;
        cin >> d;
        for (int i = 1; i <= n; i++)
        {
            for (Edge ed : EdgeList)
            {
                long long int u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;
                if (dis[u] < 1e18 && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }
        bool flag = false;
        for (Edge ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }

        else if (flag == false)
        {
            if (dis[d] != 1e18)
            {
                cout << dis[d] << endl;
            }
            else
            {
                cout << "Not Possible" << endl;
            }
        }
    }

    return 0;
}