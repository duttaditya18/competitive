#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++) cin >> a[i];

        int x = 0, y = 0;
        int maxX = 0, maxEl = -1e9 - 7;

        for(int i = 0; i < n; i++)
        {
            x += a[i];
            if(x < 0) x = 0;
            maxX = max(maxX, x);

            if(a[i] > 0) y += a[i];
            maxEl = max(maxEl, a[i]);
        }

        cout << (maxEl < 0 ? maxEl : maxX) << " " << (maxEl < 0 ? maxEl : y) << endl;
    }
    return 0;
}
