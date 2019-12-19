#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    int a, b;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        if(b < a) swap(a, b);

        if(a*2 < b)
        {
            cout << "NO\n";
            continue;
        }

        if((a % 3 == 0 && b % 3 == 0) || (a % 3 == 1 && b % 3 == 2) || (a % 3 == 2 && b % 3 == 1))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
