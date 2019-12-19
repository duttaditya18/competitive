#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int r[n + 1] = {}, c[n + 1] = {};

    for(int i = 1; i <= n; i++) cin >> r[i] >> c[i];

    sort(r, r + n);
    sort(c, c + n);

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        ans += abs(r[i] - i);
        ans += abs(c[i] - i);
    }
    cout << ans << endl;
    return 0;
}

// Format
// Size of Board
// n lines with coordinates of the guards
