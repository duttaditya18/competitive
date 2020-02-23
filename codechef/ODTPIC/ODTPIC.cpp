#include <bits/stdc++.h>

using namespace std;

const int maxa = 4*1e3;
const int maxn = 1e5;

bitset<maxa + 10> a[maxn + 10];
bitset<maxa + 10> b[maxn + 10];
bitset<maxa + 10> c;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n, m, q, x;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = a[i - 1];
        a[i][x] = !a[i][x];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> x;
        b[i] = b[i - 1];
        b[i][x] = !b[i][x];
    }

    int l[2], r[2];
    while(q--)
    {
        cin >> l[0] >> r[0] >> l[1] >> r[1];
        c = (a[r[0]]^a[l[0] - 1])^(b[r[1]]^b[l[1] - 1]);
        cout << c.count() << "\n";
    }
    return 0;
}
