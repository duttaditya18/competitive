#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    int h[n];
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    // a[i] is the minimum steps to reach the the i'th stone
    int a[n] = {};
    a[0] = 0;
    a[1] = abs(h[1] - h[0]);

    int mi;
    for(int i = 2; i < n; i++)
    {
        mi = INT_MAX;
        for(int j = 1; j <= k && j <= i; j++)
        {
            mi = min(mi, (a[i - j] + abs(h[i] - h[i - j])));
        }
        a[i] = mi;
    }
    cout << a[n - 1] << endl;
    return 0;
}
