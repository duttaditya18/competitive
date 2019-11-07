#include <bits/stdc++.h>

using namespace std;
long long t, n, cur, x, f;

int main(void)
{
    cin >> t;

    while(t--)
    {
        cur = 0;
        cin >> n;

        f = n;
        while(f--)
        {
            cin >> x;
            cur = (cur + x) % n;
        }
        if(!cur) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
