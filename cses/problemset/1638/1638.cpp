#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n][n] = {};
    char cd;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cd;
            if(cd == '.')
            {
                a[i][j] = 1;
            }
            else if(cd == '*')
            {
                a[i][j] = 0;
            }
        }
    }

    int ans[n][n] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
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
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    cout << ans[n-1][n-1] << endl;
    return 0;
}
