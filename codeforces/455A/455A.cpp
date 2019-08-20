//WA

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n], c[n + 1] ={}, ans[n + 1] = {};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    ans[0] = 0;
    ans[1] = c[1];
    for(int i = 2; i <= n; i++)
    {
        ans[i] = max(ans[i - 1], (ans[i - 2] + (c[i]*i)));
    }
    cout << ans[n];
}
