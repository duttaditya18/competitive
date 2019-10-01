#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n;
    int prf[n + 1];
    prf[0] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> prf[i + 1];
        prf[i + 1] += prf[i];
    }

    int q, l, r;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << (prf[r] - prf[l - 1]) / 10 << endl;
    }
}
