#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;

    int a[n+1]={};
    for(int i = 1; i <= n; i++) cin>>a[i];

    int b=0, w=0;

    for(int i=1; i<=n; i++)
    {
        swap(b, w);
        b += (a[i]/2) + (a[i]%2);
        w += (a[i]/2);
    }
    cout<<min(b, w) << "\n";
    return 0;
}
