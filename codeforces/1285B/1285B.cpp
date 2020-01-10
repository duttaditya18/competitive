#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int a[n];
        long long tot = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            tot += a[i];
        }

        long long cur = 0;
        long long ma1 = LLONG_MIN;
        for(int i = 1; i < n; i++)
        {
            cur += a[i];
            ma1 = max(cur, ma1);
            if(cur < 0) cur = 0;
        }
        cur = 0;
        long long ma2 = LLONG_MIN;
        for(int i = 0; i < n - 1; i++)
        {
            cur += a[i];
            ma2 = max(cur, ma2);
            if(cur < 0) cur = 0;
        }

        // cout << max(ma1, ma2) << endl;

        if(max(ma1, ma2) >= tot)
        {
            cout << "No\n";
            continue;
        }
        else
        {
            cout << "Yes\n";
            continue;
        }
    }
}
