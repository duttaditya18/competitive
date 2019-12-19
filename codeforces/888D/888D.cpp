#include <bits/stdc++.h>

using namespace std;

#define E 2.71828182845904523536

int main(void)
{
    int n, k;
    cin >> n >> k;

    long long ans = 1;
    if(k == 1)
    {
        cout << ans << endl;
        return 0;
    }


    for(int i = 2; i <= k; i++)
    {
        long long ncr = 1ll;
        for(int j = n; j > n - i; j--) ncr *= j;
        for(int j = 1; j <= i; j++) ncr /= j;

        double der = 1.0;

        for(int j = 2; j <= i; j++) der *= j;

        der = round(der/E);

        ans += ncr*der;
        //cout << i << " " << ncr << der << endl;
    }
    cout << ans;
}
