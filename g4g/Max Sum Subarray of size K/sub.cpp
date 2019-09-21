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
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int tn = 0;
        for(int i = 0; i < k; i++)
        {
            tn += a[i];
        }
        int ts = tn;
        for(int i = 1; i <= n - k; i++)
        {
            ts = ts - a[i - 1] + a[i + k - 1];
            tn = max(ts, tn);
        }
        cout << tn << endl;
    }
    return 0;
}
