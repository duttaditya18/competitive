#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c, n; cin >> a >> b >> c >> n;
    if(c >= 0 && a >= c && b >= c && n > (a + b - c))
        cout << (n - a - b + c);
    else
        cout << -1;
    cout << "\n";
}
