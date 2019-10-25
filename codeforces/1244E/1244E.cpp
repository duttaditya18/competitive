// WTF?

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    long long k;
    cin >> n >> k;

    int a[n] = {};
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    //for(int i = 0; i < n; i++) cout << a[i] << " ";
    //cout << "\n";

    int ans = a[n - 1] - a[0];
    int diff;
    for(int i = 1; i < n; i++)
    {
        //cout << ans << "\n";
        diff = a[i] - a[i - 1];

        if(k >= 1ll * diff * i)
        {
            k -= 1ll * diff * i;
            ans -= diff;
        }
        else
        {
            ans -= (k / (1ll * i));
            break;
        }

        diff = a[n - i] - a[n - i - 1];
        if(k >= 1ll * diff * i)
        {
            k -= 1ll * diff * i;
            ans -= diff;
        }
        else
        {
            ans -= (k / (1ll * i));
            break;
        }
    }

    cout << max(0, ans) << "\n";
    return 0;
}
