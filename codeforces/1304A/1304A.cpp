#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, x, y, a, b; cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if(!((y - x) % (a + b))) cout << (y - x) / (a + b);
        else cout << -1;
        cout << "\n";
    }
}
