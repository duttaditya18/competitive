#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n, d; cin >> n >> d;
        int x, c, s = 0; cin >> x;
        for(int i = 1; i < n; i++)
        {
            cin >> c;
            if(d < 0) continue;
            s += min(c, d / i);
            d -= c * i;
        }
        cout << x + s << "\n";
    }
    return 0;
}
