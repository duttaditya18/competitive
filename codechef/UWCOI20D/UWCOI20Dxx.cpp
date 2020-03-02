#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n] = {};
        char c;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> c;
                if(c - '0') a[i] = j;
            }

        // for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";

        int an = 0;

        for(int i = 0; i < n; i++)
        {
            int mn = a[i], mx = a[i];
            for(int j = i; j < n; j++)
            {
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if(mx - mn == j - i)
                {
                    an++;
                    // cout << i << " " << j << " " << mx << " " << mn << "\n";
                }
            }
        }

        cout << an << "\n";
    }
    return 0;
}
