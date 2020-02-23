#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int ncr(int n, int r)
{
    int C[r+1] = {};
    C[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]) % mod;

    return C[r];
}

int main(void)
{
    int n, m; cin >> n >> m;
    cout << ncr(2*m + n-1, 2*m) << "\n";
}
