#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int c[2] = {}, a[2] = {};
    int ma = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[0] >> a[1];
        c[0] += a[0]; c[1] += a[1];
        if(abs(c[0] - c[1]) > abs(ma)) ma = c[0] - c[1];
    }
    cout << (ma < 0 ? 2 : 1) << " " << abs(ma) << "\n";
    return 0;
}
