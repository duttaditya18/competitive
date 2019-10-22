#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        char c;
        int m = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> c;
            if(c == '1')
            {
                m = max({m, i, n - i + 1});
            }
        }
        if(m == 0) cout << n;
        else
        {
            cout << max(2*m, n + 1);
        }
        cout << "\n";
    }
    return 0;
}
