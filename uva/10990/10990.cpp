#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int maxn = 2000000;

ll phi[maxn + 10];
ll dep[maxn + 10];

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    for(int i = 2; i <= maxn; i++) phi[i] = i - 1;
    dep[1] = 0;

    for(int i = 2; i <= maxn; i++)
    {
        for(int j = i + i; j <= maxn; j += i)
            phi[j] -= phi[i];
        dep[i] = dep[phi[i]] + 1;
    }

    for(int i = 2; i <= maxn; i++) dep[i] += dep[i - 1];

    int t, m, n; cin >> t;

    while(t--)
    {
        cin >> m >> n;
        cout << dep[n] - dep[m - 1] << "\n";
    }
}
