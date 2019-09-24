#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if(a[0] + a[3] == a[1] + a[2] || a[0] + a[1] + a[2] == a[3])
    {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
