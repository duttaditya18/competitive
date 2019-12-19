#include <bits/stdc++.h>

using namespace std;
#define MAXX 100010

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, c;
        cin >> n >> x;
        int f[MAXX] = {};

        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            if(x > c)
            {
                if(f[x - c])
                {
                    ok = true;
                }
            }
            f[c] = 1;
            // cout << f[c] << " " << f[x - c] << endl;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}
