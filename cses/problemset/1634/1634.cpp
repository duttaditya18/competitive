#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];

    int ans[x + 1];
    ans[0] = 0;

    for(int i = 1; i <= x; i++)
    {
        int mini = 2147483647;
        for(int j = 0; j < n; j++)
        {
            if(i - c[j] >= 0 && ans[i - c[j]] != 2147483647)
            {
                mini = min(mini, ans[i - c[j]] + 1);
            }
        }
        ans[i] = mini;
    }
    //for(int i = 0; i <= x; i++)
    //{
        // cout << i << " : " << ans[i] << endl;
    //}
    cout << ((ans[x] == 2147483647) ? -1 : ans[x]);
    return 0;
}
