#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010

int a[MAXN], f[MAXN], ans[MAXN];

int main(void)
{
    int n, m, x; cin >> n >> m;


    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i >= 1; i--)
    {
        ans[i] += ans[i + 1];
        if(!f[a[i]])
        {
            f[a[i]] = 1;
            ans[i] += 1;
        }
    }

    while(m--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
}
