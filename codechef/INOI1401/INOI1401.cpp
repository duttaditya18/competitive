#include<bits/stdc++.h>

using namespace std;
#define MOD 20011

int main(void)
{
    int n, m, d; cin >> n >> m >> d;

    int a[n + 1][m + 1] = {};

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    if(n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    // 0 = Coming from Up, 1 = Coming from Left
    int tdp[n + 5][m + 5][2] = {};

    tdp[1][1][0] = 1;
    tdp[1][1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!a[i][j])
            {
                tdp[i][j][0] = 0;
                tdp[i][j][1] = 0;
                continue;
            }
            bool bI = true;
            bool bJ = true;
            for(int k = 1; k <= d; k++)
            {
                if((i - k) >= 1)
                {
                    if(!a[i - k][j]) bI = false;
                    if(bI) tdp[i][j][0] = (tdp[i][j][0] + tdp[i - k][j][1]) % MOD;
                }
                if((j - k) >= 1)
                {
                    if(!a[i][j - k]) bJ = false;
                    if(bJ) tdp[i][j][1] = (tdp[i][j][1] + tdp[i][j - k][0]) % MOD;
                }
            }
        }
    }

    cout << (tdp[n][m][0] + tdp[n][m][1]) % MOD << endl;
}
