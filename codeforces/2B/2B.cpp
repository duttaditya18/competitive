#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, inp;
    cin >> n;

    int a[n + 1][n + 1] = {}, two[n + 1][n + 1] = {}, five[n + 1][n + 1] = {};
    int zeroEx = false, i0 = 0, j0 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> inp;
            a[i][j] = inp;
            if(inp == 0)
            {
                zeroEx = true;
                i0 = i;
                j0 = j;
                continue;
            }
            two[i][j] = __builtin_ctz(inp & (~(inp - 1)));
            while(!(inp % 5))
            {
                five[i][j]++;
                inp /= 5;
            }
        }
    }

    int dp2[n + 1][n + 1] = {}, dp5[n + 1][n + 1] = {};

    for(int i = n; i >= 0; i--)
    {
        for(int j = n; j >= 0; j--)
        {
            dp2[i][j] = two[i][j];
            if(j == n && i == n)
            {
                continue;
            }
            if(j == n)
            {
                dp2[i][j] += dp2[i + 1][j];
                continue;
            }
            if(i == n)
            {
                dp2[i][j] += dp2[i][j + 1];
                continue;
            }
            dp2[i][j] += min(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }
    for(int i = n; i >= 0; i--)
    {
        for(int j = n; j >= 0; j--)
        {
            dp5[i][j] = five[i][j];
            if(j == n && i == n)
            {
                continue;
            }
            if(j == n)
            {
                dp5[i][j] += dp5[i + 1][j];
                continue;
            }
            if(i == n)
            {
                dp5[i][j] += dp5[i][j + 1];
                continue;
            }
            dp5[i][j] += min(dp5[i + 1][j], dp5[i][j + 1]);
        }
    }

    if(zeroEx)
    {
        // cout << i0 << " " << j0 << endl;
        if(min(dp2[1][1], dp5[1][1]) > 1)
        {
            cout << 1 << endl;
            for(int i = 1; i < i0; i++) cout << "D";
            for(int j = 1; j < j0; j++) cout << "R";
            for(int i = i0; i < n; i++) cout << "D";
            for(int j = j0; j < n; j++) cout << "R";
            return 0;
        }
    }

    if(dp2[1][1] <= dp5[1][1])
    {
        cout << dp2[1][1] << endl;
        int i = 1, j = 1;
        while(i != n || j != n)
        {
            if(i == n)
            {
                cout << "R";
                j++;
            }
            else if(j == n)
            {
                cout << "D";
                i++;
            }
            else
            {
                if(dp2[i + 1][j] <= dp2[i][j + 1])
                {
                    cout << "D";
                    i++;
                }
                else
                {
                    cout << "R";
                    j++;
                }
            }
        }
    }
    else
    {
        cout << dp5[1][1] << endl;
        int i = 1, j = 1;
        while(i != n || j != n)
        {
            if(i == n)
            {
                cout << "R";
                j++;
            }
            else if(j == n)
            {
                cout << "D";
                i++;
            }
            else
            {
                if(dp5[i + 1][j] <= dp5[i][j + 1])
                {
                    cout << "D";
                    i++;
                }
                else
                {
                    cout << "R";
                    j++;
                }
            }
        }
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << two[i][j] << " "; } cout << endl; } cout << endl;
    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << dp2[i][j] << " "; } cout << endl; } cout << endl;
    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << five[i][j] << " "; } cout << endl; } cout << endl;
    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << dp5[i][j] << " "; } cout << endl; } cout << endl;
}
