#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mab = 40;

int main(void)
{
    ll n, k; cin >> n >> k;
    ll x;
    int p[mab] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        for(int j = 0; j < mab; j++)
            p[j] += ((x >> j) & 1);
    }

    // for(int j = 0; j < mab; j++) cout << p[j];
    // cout << endl;

    ll s = (n / 2) + (n % 2);
    ll ca = 0;
    ll an = 0;

    for(int i = mab - 1; i >= 0; i--)
    {
        if((k >> i) & 1)
        {
            // cout << i << endl;
            ca = 0;
            for(int j = mab - 1; j >= i + 1; j--)
            {
                // cout << j << " ";
                if((k >> j) & 1) ca += ((n - p[j]) * (1LL << j));
                else ca += (p[j] * (1LL << j));
            }
            // cout << " : ";
            ca += (p[i] * (1LL << i));
            for(int j = i - 1; j >= 0; j--)
            {
                // cout << j << " ";
                if(p[j] >= s) ca += (p[j] * (1LL << j));
                else ca += ((n - p[j]) * (1LL << j));
            }
            // cout << ca << endl;
            an = max(an, ca);
        }
        if(i == 0)
        {
            ca = 0;
            for(int j = mab - 1; j >= 0; j--)
            {
                if((k >> j) & 1) ca += ((n - p[j]) * (1LL << j));
                else ca += (p[j] * (1LL << j));
            }
            an = max(an, ca);
        }
    }

    cout << an << "\n";
    return 0;
}
