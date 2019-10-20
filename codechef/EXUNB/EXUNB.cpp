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
        if(!(n % 2))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(((abs(i - j) % 2) and i > j) || ((!(abs(i - j) % 2)) and j > i) and i - j != 0) cout << 1;
                else cout << 0;
            }
            cout << "\n";
        }
    }
}
