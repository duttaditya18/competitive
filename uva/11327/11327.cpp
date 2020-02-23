#include <bits/stdc++.h>

using namespace std;
const int maxn = 2*1e5;

long long phi[maxn + 10], n = 1, x, y, z;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    phi[1] = 0;
    for(int i = 2; i <= maxn; i++) phi[i] = i-1;
    for(int i = 1; i <= maxn; i++)
    {
        for(int j = 2*i; j <= maxn; j += i)
            phi[j] -= phi[i];
        phi[i] += phi[i - 1];
    }

    while(1)
    {
        cin >> n;

        if(n == 0) break;
        if(n == 1)
        {
            cout << "0/1\n";
            continue;
        }
        else if(n == 2)
        {
            cout << "1/1\n";
            continue;
        }
        n -= 2;

        // for(int i = 1; i <= n; i++) cout << i << " : " << phi[i] << "\n";

        x = lower_bound(phi, phi + maxn, n) - phi;
        y = n - phi[x - 1];
        z = 0;

        // cout << x << " " << y << " " << z << "\n";

        for(long long i = 1; i <= x; i++)
        {
            z += (__gcd(x, i) == 1);
            if(z == y)
            {
                cout << i << "/" << x << "\n";
                break;
            }
        }
    }
}
