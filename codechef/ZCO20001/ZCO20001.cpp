#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        ll p, id; cin >> p >> id;
        ll ans = 0;

        for(int i = 0; i < p; i++)
        {
            // cout << (1LL << p - i - 1) << " " << (1LL << i) << " ";
            if(id >= (1LL << p - i - 1))
            {
                // cout << "y";
                // cout << (1LL << i) << "\n";
                ans |= (1LL << i);
                // cout << id << " " << (1LL << p - i) << "\n";
                id ^= (1LL << p - i - 1);
            }
            // cout << endl;
        }
        cout << ans << "\n";
    }
    return 0;
}
