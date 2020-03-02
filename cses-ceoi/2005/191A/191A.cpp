#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, x, y; cin >> n >> m;
    int a[(n * m) + 2] = {};
    for(int i = 1; i <= (n * m); i++) cin >> a[i];

    int q; cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        swap(a[x], a[y]);
        for(int i = 1; i <= (n * m) + 1; i++) cout << a[i] << " "; cout << "\n";
    }

    for(int i = 1; i <= (n * m) + 1; i++) cout << a[i] << " ";
}
