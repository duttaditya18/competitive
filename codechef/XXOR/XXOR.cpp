#include <bits/stdc++.h>

using namespace std;

const int mab = 31;

int main(void)
{
    // cout << bitset<32>((1LL << 31) - 1);

    int n, q, x, s, l, r; cin >> n >> q;

    int p[n + 1][mab] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        for(int j = 0; j < mab; j++)
        {
            p[i][j] = p[i - 1][j];
            if((x >> j) & 1) p[i][j]++;
        }
    }

    while(q--)
    {
        cin >> l >> r;
        s = r - l + 1;
        x = 0;
        for(int j = 0; j < mab; j++)
        {
            if(p[r][j] - p[l - 1][j] < ((s / 2) + (s % 2)))
            {
                x |= (1 << j);
                // cout << 1;
            }
            // else cout << 0;
        }
        // cout << "\n";
        cout << x << "\n";
    }
    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < mab; j++)
            cout << p[i][j];
        cout << "\n";
    }*/
    return 0;
}
