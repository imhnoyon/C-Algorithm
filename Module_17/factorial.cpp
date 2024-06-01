#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{

    // base case
    if (n == 0)
        return 1;
    int f = fact(n - 1);
    return f * n;
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}