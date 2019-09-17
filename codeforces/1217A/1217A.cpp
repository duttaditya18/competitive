#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, s, i, e, x;
    cin >> t;
    while(t--)
    {
        cin >> s >> i >> e;
        if(s + e <= i)
        {
            cout << 0;
        }
        else
        {
            x = (s + e - i) / 2;
            if((s + e - i) % 2)
            {
                x++;
            }
            x = min(x, e + 1);
            cout << max(0, x);
        }
        cout << endl;
    }
    return 0;
}
