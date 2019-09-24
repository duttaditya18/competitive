#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    char c;
    int a[n + 1][m + 1] = {};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (c == '1');
        }
    }

    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/

    int ma = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = i; k <= n; k++)
            {
                for(int l = j; l <= m; l++)
                {
                    if(a[k][l] == a[i - 1][l] + a[k][j - 1] - a[i - 1][j - 1])
                        ma = max(ma, 2 * ((k - i + 1) + (l - j + 1)));
                }
            }
        }
    }

    cout << ma << endl;
    return 0;
}
