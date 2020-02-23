#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int phi[MAXN + 10];
int t, g, n;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    for(int i = 1; i <= MAXN; i++)
    {
        g = i, n = i;
        for(int j = 2; j*j <= n; j++)
        {
            if(!(n % j))
            {
                while(!(n % j)) n /= j;
                g -= (g / j);
            }
        }
        if(n > 1) g -= (g / n);
        phi[i] = g;
    }

    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << phi[n] << "\n";
    }
}
