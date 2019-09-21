#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int n[t];
    int ma = 0;
    for(int i = 0; i < t; i++)
    {
        cin >> n[i];
        ma = max(ma, n[i]);
    }
    int c = 1;

    long long ans[ma + 2] = {};
    for(int i = 1; i < ma + 2; i++)
    {
        ans[i] = 1;
    }

    for(int i = 1; i <= ma; i++)
    {
        for(int j = 0; j < i; j++)
        {
            ans[i] *= c;
            //cout << i << " " << j << " " << c << " " << ans[i] << endl;
            c++;
        }
        ans[i] += ans[i - 1];
    }

    //cout << endl;

    /*for(int i = 0; i < ma; i++)
    {
        cout << ans[i] << endl;
    }*/

    for(int i = 0; i < t; i++)
    {
        cout << ans[n[i]] << endl;
    }
    return 0;
}
