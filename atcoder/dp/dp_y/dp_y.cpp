// TLE Obviously

#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int a[n][m] = {};
    char cd;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] = 1;
        }
    }

    int x;
    cin >> x;
    int cx, cy;

    for(int i = 0; i < x; i++)
    {
        cin >> cx >> cy;
        a[cx - 1][cy - 1] = 0;
    }

    int ans[n][m] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != 0)
            {
                if(i == 0 && j != 0)
                {
                    ans[i][j] = ans[i][j - 1];
                }
                else if(i != 0 && j == 0)
                {
                    ans[i][j] = ans[i - 1][j];
                }
                else if(i == 0 && j == 0)
                {
                    ans[i][j] = 1;
                }
                else
                {
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                }
                ans[i][j] %= MOD;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    cout << ans[n - 1][m - 1] << endl;
    return 0;
}
