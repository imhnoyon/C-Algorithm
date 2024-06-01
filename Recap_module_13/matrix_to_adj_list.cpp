#include <bits/stdc++.h>
using namespace std;
int n;
int mat[50][50];
void convert1()
{
    vector<int> v[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int child : v[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }
}
int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    convert1();
    return 0;
}