#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // cout << (1 << 1);
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int to = 0;

    for(int mask = 0; mask < (1 << n); mask++)
    {
        to = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i)) to += a[i];
            else to -= a[i];
        }
        if((to % 360) == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
