#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;

    if(b > a) swap(a, b);
    int ans = 0, div, rem = 1;

    while(rem != 0)
    {
        rem  = a % b;
        div = a / b;
        ans += div;
        a = b;
        b = rem;
        // cout << a << " " << b << " " << div << " " << rem << endl;
    }
    cout << ans - 1 << endl;
}
