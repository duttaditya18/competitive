#include <bits/stdc++.h>

using namespace std;
const int MAXN = (int) 1e6 + 10;
const int MAXM = (int) 1e3 + 10;

bool dp[2][MAXM];
int a[MAXN];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        if(!a[i])
        {
            cout << "YES\n";
            return 0;
        }
    }

    if(n > m)
    {
        cout << "YES\n";
        return 0;
    }

    int cur = 1;

    for(int i = 0; i < n; i++)
    {
        cur = !cur;
        dp[cur][a[i]] = 1;
        if(i == 0) continue;
        for(int j = m - 1; j >= 0; j--)
        {
            if(dp[!cur][j])
            {
                int x = (j + a[i]) % m;
                dp[cur][j] = 1;
                dp[cur][x] = 1;
            }
        }
    }

    if(dp[cur][0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
