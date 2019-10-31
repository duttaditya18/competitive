#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n] = {};

        for(int i = 0; i < n; i++) cin >> a[i];

        int l = 0, r = 0;

        int curSum = 0;
        bool x = false;
        for(int r = 0; r < n; r++)
        {
            // cout << l << r << endl;
            curSum += a[r];

            while(curSum > k)
            {
                curSum -= a[l];
                l++;
            }

            if(curSum == k)
            {
                x = true;
                cout << l + 1 << " " << r + 1;
                break;
            }
        }

        if(!x) cout << -1;
        cout << endl;
    }
}
