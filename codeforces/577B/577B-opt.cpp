#include <bits/stdc++.h>

using namespace std;

bool dp[2][1007];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    if(n > m)
    {
        cout << "YES\n";
        return 0;
    }

    int f;

    for(int i = 0; i < n; i++)
    {
        cin >> f;
        f %= m;
        if(!f)
        {
            cout << "YES\n";
            return 0;
        }

        dp[i % 2][f] = 1;
        if(i == 0) continue;
        for(int j = m - 1; j >= 0; j--)
        {
            if(dp[!(i % 2)][j])
            {
                dp[i % 2][j] = 1;
                dp[i % 2][(j + f) % m] = 1;
            }
        }
    }

    if(dp[!(n % 2)][0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
