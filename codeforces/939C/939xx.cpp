#include <bits/stdc++.h>

using namespace std;

int main(void)
{

    int n;
    cin >> n;
    int a[n + 1] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int s, f;
    cin >> s >> f;

    int sum = 0;

    for(int i = s; i < f; i++)
    {
        sum += a[i];
    }

    // cout << sum << endl;

    int msum = sum, ans = 1, t = 2;

    int last;

    for(int i = s - 1; t <= n; i--, t++)
    {
        if(i <= 0) i = n;
        sum += a[i];
        last = (i + (f - s)) % n;
        if(last == 0) last = n;
        sum -= a[last];
        if(sum > msum)
        {
            msum = sum;
            ans = t;
        }
        // cout << t << " : " <<  sum << endl;
    }
    cout << ans << endl;
}
