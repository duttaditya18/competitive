#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    int a, b, c, d, k, x, y;
    while(t--)
    {
        cin >> a >> b >> c >> d >> k;
        x = (a / c);
        y = (b / d);
        if(a % c) x++;
        if(b % d) y++;

        if(x + y <= k) cout << x << " " << y;
        else cout << -1;

        cout << "\n";
    }
    return 0;
}
