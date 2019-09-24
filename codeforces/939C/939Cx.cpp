#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[2 * (n + 1)] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }

    int s, f;
    cin >> s >> f;

    int d = f - s;
    int x = 0, xsf = 0;
    for(int i = 1; i <= (f - s); i++)
    {
        x += a[i];
    }
    xsf = x;

    int mi = 1;

    for(int i = 2; i <= n; i++)
    {
        x = x - a[i - 1] + a[i + d - 1];
        if(x > xsf)
        {
            mi = i;
            xsf = x;
        }
    }

    cout << mi  << endl;

    int ans = (((s - (mi - 1)) % n) + n) % n;
    if(ans == 0) ans = n;

    cout << ans << endl;
}
