#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(void)
{
    int n;
    cin >> n;

    int a[n + 30] = {};

    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    a[5] = 16;
    a[6] = 32;

    if(n < 7)
    {
        cout << a[n];
        return 0;
    }

    for(int i = 7; i <= n; i++)
    {
        for(int j = i - 6; j < i; j++)
        {
            a[i] = (a[i] + a[j]) % MOD;
        }
    }

    cout << a[n] << endl;
}
