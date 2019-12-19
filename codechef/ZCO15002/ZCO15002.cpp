#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int r = 1;
    long long ans = 0;

    for(int i = 0; i < n; i++)
    {
        while(r < n)
        {
            if(a[r] - a[i] >= k)
            {
                ans += 1ll * n - r;
                break;
            }
            r++;
        }
    }
    cout << ans << endl;

}
