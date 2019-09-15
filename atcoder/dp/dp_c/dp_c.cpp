#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int a[3][n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    }

    int x[3][n];
    x[0][0] = max(a[1][0], a[2][0]);
    x[1][0] = max(a[2][0], a[0][0]);
    x[2][0] = max(a[0][0], a[1][0]);
    for(int i = 1; i < n; i++)
    {
        x[0][i] = a[0][i] + max(x[1][i - 1], x[2][i - 1]);
        x[1][i] = a[1][i] + max(x[2][i - 1], x[0][i - 1]);
        x[2][i] = a[2][i] + max(x[0][i - 1], x[1][i - 1]);
    }
    cout << max({x[0][n - 1], x[1][n - 1], x[2][n - 1]}) << endl;
    return 0;
}
