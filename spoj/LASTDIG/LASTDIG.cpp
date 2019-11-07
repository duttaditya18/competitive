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
        if(a == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if(b == 0)
        {
            cout << 1 << endl;
            continue;
        }

        a %= 10;

        int x = a;

        vector<int> c;
        c.push_back(x);
        x *= a;
        x %= 10;

        while(c[0] != x)
        {
            c.push_back(x);
            x *= a;
            x %= 10;
        }
        cout << c[((b - 1) % c.size())] << endl;
    }
    return 0;
}
