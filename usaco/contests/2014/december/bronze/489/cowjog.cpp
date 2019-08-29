#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ifstream cin("cowjog.in");
    ofstream cout("cowjog.out");
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int curslow = INFINITY;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        curslow = min(curslow, b[i]);
        if(b[i] <= curslow)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
