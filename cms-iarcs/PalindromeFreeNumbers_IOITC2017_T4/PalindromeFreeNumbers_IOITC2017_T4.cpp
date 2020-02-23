#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(string s)
{
    ll ans = 0;
    ll n = s.size();

    ll c = 1;
    for(int i = 1; i <= n - 1; i++)
    {
        if(i == 1) ans += 10;
        else if(i == 2)
        {
            c = 81;
            ans += c;
        }
        else
        {
            c *= 8;
            ans += c;
        }
    }

    ll x;
    for(int i = 0; i < n; i++)
    {
        x = s[i] - '0';
        if(x == 0) continue;
        else if(x == s[i - 1] - '0') break;
        if(i == 0)
        {
            c = 9;
            for(int j = 1; j <= (n - 2); j++) c *= 8;
            ans += c * (x - 1);
        }
        else if(i > 0)
        {
            c = 1;
            for(int j = 1; j <= (n - 1 - i); j++) c *= 8;
            cout << i << " " << c * (x - (x >= (s[i - 1] - '0'))) << "\n";
            ans += c * (x - (x > (s[i - 1] - '0')));
        }
    }
    return ans;
}

int main(void)
{
    cout << f("70010");
}
