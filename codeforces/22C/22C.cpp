#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;

    if(m < n - 1 || m > ((n * (n - 1) / 2) - (n - 2)))
    {
        cout << -1 << "\n";
        return 0;
    }

    int sV = (v == 1 ? 2 : 1);

    m -= n - 1;

    for(int i = 1; i <= n; i++)
    {
        if(i != v) cout << v << " " << i << "\n";
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(m == 0) break;
            if(i != v && j != v && i != sV && j != sV)
            {
                m--;
                cout << i << " " << j << "\n";
            }
        }
    }

    return 0;
}
