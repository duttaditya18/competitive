#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n], to = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        to += a[i];
    }
    sort(a, a + n);
    int i = n - 1, cu = 0;

    while(i >= 0)
    {
        cu += a[i];
        if(cu > to - cu) break;
        i--;
    }
    cout << (n - i) << "\n";
    return 0;
}
