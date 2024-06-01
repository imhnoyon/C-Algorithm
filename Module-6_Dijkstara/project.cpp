#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
using namespace std;

const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty()) {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        for (pair<int, int> child : v[node]) {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    map<string, int> locationToId;

    for (int i = 0; i < n; i++) {
        string location;
        cin >> location;
        locationToId[location] = i;
    }

    while (e--) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        v[locationToId[a]].push_back({locationToId[b], c});
        v[locationToId[b]].push_back({locationToId[a], c});
    }

    for (int i = 0; i < n; i++) {
        dis[i] = numeric_limits<int>::max();
    }
    
    dijkstra(locationToId["Uttara"]);

    cout << "Shortest distance to Motijhil: " << dis[locationToId["motijhil"]] << endl;

    return 0;
}
