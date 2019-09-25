#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int q, n, m;
    cin >> q;
    while(q--)
    {
        cin >> n;
        m = n % 4;

        if(m == 0)
        {
            if(n < 4)
            {
                cout << -1 << endl;
                continue;
            }
            cout << n/4 << endl;
        }
        else if(m == 1)
        {
            if(n < 9)
            {
                cout << -1 << endl;
                continue;
            }
            cout << ((n - 9)/4) + 1 << endl;
            continue;
        }
        else if(m == 2)
        {
            if(n < 6)
            {
                cout << -1 << endl;
                continue;
            }
            cout << ((n - 6)/4) + 1 << endl;
        }
        else if(m == 3)
        {
            if(n < 15)
            {
                cout << -1 << endl;
                continue;
            }
            cout << ((n - 15)/4) + 2 << endl;
        }
    }
}
