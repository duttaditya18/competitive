#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007;

int main(void)
{
    int n , x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int ans[x + 1] = {};
    ans[0] = 1;

    for(int i = 0; i < n; i++)
    {
        //cout << "c[i]: " << c[i] << endl;
        for(int j = 1; j <= x; j++)
        {
            //cout << " j: " << j;
            if(c[i] <= j)
            {
                ans[j] += ans[j - c[i]];
                ans[j] %= MOD;
            }
        }
        //cout << endl << endl;
    }
    cout << ans[x] << endl;
    return 0;
}
