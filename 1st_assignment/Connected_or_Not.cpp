#include <bits/stdc++.h>
using namespace std;
int mat[1000][1000];
int main()
{
    int n, e;
    cin >> n >> e;
    memset(mat,0,sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int val, value;
        cin >> val >> value;
        if (val == value)
            cout << "YES" << endl;
        else if (mat[val][value] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}