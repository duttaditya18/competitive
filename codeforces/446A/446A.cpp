#include <bits/stdc++.h>

using namespace std;
#define INF 1010000000

int main(void)
{
    int n;
    cin >> n;

    int a[n + 2] = {};
    a[0] = -INF;
    a[n + 1] = INF;

    int stat[n + 2] = {}, enat[n + 2] = {};

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] > a[i - 1]) enat[i] = enat[i - 1] + 1;
        else enat[i] = 1;
    }

    for(int i = n; i >= 1; i--)
    {
        if(a[i + 1] > a[i]) stat[i] = stat[i + 1] + 1;
        else stat[i] = 1;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(a[i + 1] > a[i - 1] + 1) ans = max(ans, enat[i - 1] + 1 + stat[i + 1]);
        ans = max({ans, enat[i - 1] + 1, 1 + stat[i + 1]});
    }

    cout << ans << endl;

    // for(int i = 0; i <= n + 1; i++) cout << a[i] << " "; cout << endl;
    // for(int i = 0; i <= n + 1; i++) cout << stat[i] << " "; cout << endl;
    // for(int i = 0; i <= n + 1; i++) cout << enat[i] << " "; cout << endl;
}
