#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n, q; cin>>n>>q;
    // 0 = Empty, 1 = Occupied
    int a[n+2][2] = {};

    int x, y;
    int ax = 0;
    while(q--)
    {
        cin >> x >> y;
        if(a[y][x-1]) ax -= (a[y][!(x-1)] + a[y-1][!(x-1)] + a[y+1][!(x-1)]);
        else ax += (a[y][!(x-1)] + a[y-1][!(x-1)] + a[y+1][!(x-1)]);
        a[y][x-1] = !a[y][x-1];
        if(!ax) cout<<"Yes";
        else cout<<"No";
        cout<<"\n";
    }
    return 0;
}
