#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, x; cin >> n;
        int a[111] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
        }
        int ans = 0;
        for(int i = 0; i < 111; i++)
        {
            ans = max(ans, a[i]);
        }
        cout << n - ans << endl;
    }
}
