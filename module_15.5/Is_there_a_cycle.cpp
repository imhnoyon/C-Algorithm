#include <bits/stdc++.h>
using namespace std;
const int N = 55;
vector<int> v[N];
bool vis[N];
int pathvis[N];
bool ans = false;
void dfs(int parent)
{
    vis[parent] = true;
    pathvis[parent] = true;
    for (int child : v[parent])
    {
        if (pathvis[child] == true)
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
    pathvis[parent] = false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

    for (int i = 1; i <= n; i++)
    {

        dfs(i);
    }

    if (ans)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0";
    }
    return 0;
}
