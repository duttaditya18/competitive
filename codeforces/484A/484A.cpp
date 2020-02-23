#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int t; cin >> t;

    ll l, r;
    while(t--)
    {
        cin >> l >> r;
        bitset<70> a(l);
        bitset<70> b(r);

        // cout << a << " " << b << "\n";

        int n = a.size();
        bitset<70> c;

        if(l == r) cout << l;
        else
        {
            for(int i = n; i >= 0; i--)
            {
                if(b[i] && a[i]) c[i] = 1;
                else if(b[i] && !a[i])
                {
                    for(int j = i - 1; j >= 0; j--) c[j] = 1;
                    if(i == 0) c[i] = 1;
                    break;
                }
            }
            cout << (b.count() > c.count() ? b.to_ullong() : c.to_ullong());
        }
        cout << "\n";

    }
}
