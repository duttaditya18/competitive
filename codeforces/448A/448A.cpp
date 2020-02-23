#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a[3], b[3], n;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> n;

    if(((a[0] + a[1] + a[2]) / 5) + !!((a[0] + a[1] + a[2]) % 5) + ((b[0] + b[1] + b[2]) / 10) + !!((b[0] + b[1] + b[2]) % 10) <= n) cout << "YES";
    else cout << "NO";
    cout << "\n";
}
