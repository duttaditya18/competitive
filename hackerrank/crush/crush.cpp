#include <bits/stdc++.h>

using namespace std;
#define MAXN 10000010

long long d[MAXN];

int main(void)
{
    int n, m;
    cin >> n >> m;

    long long k;
    int a, b;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> k;
        d[a - 1] += k;
        d[b] -= k;
    }

    long long ma = 0, cur = 0;
    for(int i = 0; i <= n; i++)
    {
        cur += d[i];
        ma = max(ma, cur);
    }

    // for(int i = 0; i <= n + 1; i++) cout << x[i] << " "; cout << endl;
    // for(int i = 0; i <= n + 1; i++) cout << d[i] << " "; cout << endl;
    cout << ma << endl;
}
