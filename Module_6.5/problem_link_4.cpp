#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int, int>> v[105];
int dis[N];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    for (int i = 0; i < N; i++)
    {
        dis[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int pnode = par.first;
        int pcost = par.second;

        for (pair<int, int> c : v[pnode])
        {
            int cnode = c.first;
            int ccost = c.second;

            if (pcost + ccost < dis[cnode])
            {
                dis[cnode] = pcost + ccost;
                pq.push({cnode, pcost + ccost});
            }
        }
    }
}

int main()
{
    int n, src, des;
    cin >> n >> src >> des;

    int matrix[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] >=0)
            {
                v[i].push_back({j, matrix[i][j]});
            }
        }
    }
    dijkstra(src);

    if (dis[des] == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << dis[des] << endl;
    }
}
