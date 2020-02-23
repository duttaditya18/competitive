#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        if(!(n % 2)) cout << string(n/2, '1');
        else cout << '7' << string((n - 3)/2, '1');
        cout << "\n";
    }
    return 0;
}
