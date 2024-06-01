#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int dis[N];
vector<pair<int, int>> v[N];
void dijkstra(int src)
{
  queue<pair<int, int>> q;
  q.push({src, 0});
  dis[src] = 0;
  while (!q.empty())
  {
    pair<int, int> parent = q.front();
    q.pop();
    int node = parent.first;
    int cost = parent.second;
    for (pair<int, int> child : v[node])
    {
      int childNode = child.first;
      int childCost = child.second;
      if (cost + childCost < dis[childNode])
      {
        dis[childNode] = cost + childCost;
        q.push({childNode, dis[childNode]});
      }
    }
  }
}
int main()
{
  int n, e;
  cin >> n >> e;
  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  // memset(dis, INT_MAX, sizeof(dis));
  for (int i = 0; i < n; i++)
  {
    dis[i] = INT_MAX;
  }
  dijkstra(0);
  for (int i = 0; i < n; i++)
  {
    cout << i << " " << dis[i] << endl;
  }

  return 0;
}
