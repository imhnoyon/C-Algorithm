#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        int mx1 = INT_MIN;
        int idx1 = -1;
        int mx2 = INT_MIN;
        int idx2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (ar[i] > mx1)
            {
                mx1 = ar[i];
                idx1 = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == idx1)
                continue;
            else if (ar[i] > mx2)
            {
                mx2 = ar[i];
                idx2 = i;
            }
        }

        // cout<<idx1<<" "<<idx2<<endl;

        int ans, res;
        res = min(idx1, idx2);
        ans = max(idx1, idx2);
        cout << res << " " << ans << endl;
    }
    return 0;
}