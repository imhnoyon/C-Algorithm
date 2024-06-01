#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];
int n, e;
// void bfs(int src)
// {
//     queue<int> q;
//     q.push(src);
//     vis[src] = true;
//     vector<int> v2;
//     while (!q.empty())
//     {
//         int par = q.front();
//         q.pop();

//         if (!v[par].empty())
//         {
//             for (int x : v[par])
//             {
//                 //  cout<<x<<" ";
//                 v2.push_back(x);
//                 sort(v2.begin(), v2.end(), greater<int>());
//             }
//         }
//         else
//         {
//             cout<<"-1";
//         }
//         for (int ans : v2)
//         {
//             cout << ans << " ";
//         }
//         cout << endl;
//     }
// }

bool dfs(int src)
{
    for (int i = 0; i < n; i++)
    {
        for (int x : v[i])
        {
            if (src == x)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> v2;

    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;

    while (q--)
    {
        int src;
        cin >> src;
        if (dfs(src) == true)
        {

            for (int x : v[src])
            {
                v2.push_back(x);
            }
            sort(v2.begin(), v2.end(), greater<int>());
            for (int ans : v2)
            {
                cout << ans << " ";
            }
        }
        else
        {
            cout<<"-1";
        }
        cout << endl;
        v2.clear();
    }

    return 0;
}