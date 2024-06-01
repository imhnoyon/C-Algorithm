#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int mat[n][n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<pair<int, int>> v[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > 0)
            {
                v[i].push_back({j, mat[i][j]});
                v[j].push_back({i, mat[i][j]});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> child : v[i])
        {
            cout << child.first << ",";
            cout<<child.second;
        }
        cout << endl;
    }
    return 0;
}