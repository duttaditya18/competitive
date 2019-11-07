#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    int a, b;
    while(t--)
    {
        cin >> a >> b;
        if(__gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}
