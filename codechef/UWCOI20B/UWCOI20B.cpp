#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int o = 0, e = 0, x;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            o += (x % 2);
            e += !(x % 2);
        }
        cout << 1ll*o*e << "\n";
    }
    return 0;
}
