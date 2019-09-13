#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(void)
{
    int n;
    cin >> n;
    long long s[2][n + 1];

    // s[1] - Not coming back to D
    // s[0] - Coming back to D
    s[0][1] = 0;
    s[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        s[0][i] = (3 * s[1][i - 1]) % MOD;
        s[1][i] = ((2 * s[1][i - 1]) + s[0][i - 1]) % MOD;
    }
    cout << s[0][n] << endl;
    return 0;
}
