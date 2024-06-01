#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    int fabonacci = fibo(n - 1) + fibo(n - 2);
    return fabonacci;
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}