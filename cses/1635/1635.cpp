#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];

    int ans[x + 1] = {};
    ans[0] = 0;
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++)
            if(i - c[j] >= 0)
            {
                ans[i] += ans[i - c[j]];
                if(i == c[j])
                    ans[i] += 1;
                ans[i] = ans[i] % 1000000007;
            }

    cout << ans[x] << endl;
    return 0;
}
