#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n + 1][n + 1] = {};
        char c;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> c;
                a[i][j] = (c - '0');
                a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
            cout << "\n";
        }

        int ans = 0;

        for(int k = 0; k < n; k++)
        {
            for(int i = 1; i <= n - k; i++)
            {
                for(int j = 1; j <= n - k; j++)
                {
                    if(a[i + k][j + k] - a[i + k][j - 1] - a[i - 1][j + k] + a[i - 1][j - 1] == k + 1)
                    {
                        // cout << i << " " << j << " : ";
                        // cout << i + k << " " << j + k << " : " << a[i + k][j + k] << " " << a[i - 1][j] << " "<< a[i][j - 1] << ' ' << a[i - 1][j - 1] << "\n";
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
