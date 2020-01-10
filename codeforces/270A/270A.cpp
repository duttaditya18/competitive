#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, a, n; cin >> t;

    while(t--)
    {
        cin >> a;
        if(!(360 % (180 - a))) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}
