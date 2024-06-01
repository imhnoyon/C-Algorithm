#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 100;
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }
    // while (n--)  // adj list er jonno eita
    // {
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     mat[a][b] = c;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 100)
            {
                cout << "100"
                     << " ";
            }
            else
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}