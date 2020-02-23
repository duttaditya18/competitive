#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x; cin >> n;
    int m=INT_MIN, t=0;
    for(int i=0; i<n; i++) cin >> x, m=max(x, m), t+=x;
    cout << (n*m)-t<<"\n";
    return 0;
}
